from fastapi import FastAPI,Request,Response,status,Security
from fastapi.responses import RedirectResponse
from fastapi_jwt import JwtAuthorizationCredentials, JwtAccessBearer
from passlib.context import CryptContext
from database import initdb
import psycopg2
import base62
from datetime import timedelta
from dotenv import load_dotenv
import os
from models import User,ResponseMessage,LongURL,AuthToken

load_dotenv()

DATABASE=os.getenv("DATABASE")
DATABASE_USER=os.getenv("DATABASE_USER")
DATABASE_PASSWORD=os.getenv("DATABASE_PASSWORD")
DATABASE_HOST=os.getenv("DATABASE_HOST")
JWT_SECRET=os.getenv("JWT_SECRET")
JWT_EXPIRY=int(os.getenv("JWT_EXPIRY"))


conn = psycopg2.connect(database=DATABASE,
                        user=DATABASE_USER,
                        password=DATABASE_PASSWORD,
                        host=DATABASE_HOST)
initdb(conn)

app = FastAPI()
access_security = JwtAccessBearer(secret_key=JWT_SECRET,
                                  auto_error=True,
                                  access_expires_delta=timedelta(seconds=JWT_EXPIRY))

pwd_context = CryptContext(schemes=["argon2"],deprecated="auto")

@app.post("/register",status_code=201)
def registerUser(user:User,response:Response):
    curr = conn.cursor()
    try:
        curr.execute("insert into user_table values(%s,%s);",[str(user.email),pwd_context.hash(user.password)])
        conn.commit()
        curr.close()
        return ResponseMessage(message="Sucessfully registered")
    
    except psycopg2.errors.UniqueViolation:
        conn.rollback()
        curr.close()
        response.status_code = status.HTTP_409_CONFLICT
        return ResponseMessage(message="Already registered")

@app.post("/login",status_code=200)
def loginUser(user:User,response:Response):
    curr = conn.cursor()
    curr.execute("select * from user_table where email = %s;",[str(user.email)])
    result = curr.fetchone()
    curr.close()

    if((not result) or (not pwd_context.verify(user.password,result[1]))):
        response.status_code = status.HTTP_403_FORBIDDEN
        return ResponseMessage(message="Username or Password is wrong")
    
    token = access_security.create_access_token(user.model_dump(exclude=("password")))

    return AuthToken(token=token)
    

@app.post("/shorten",status_code=201)
def shorten(url:LongURL,request:Request,credentials : JwtAuthorizationCredentials = Security(access_security)):  
    curr = conn.cursor()
    curr.execute("""insert into url_table(hash,url,user_email) values (md5(%s)::uuid,%s,%s) on conflict do nothing""",[str(url.url),str(url.url),str(credentials["email"])])
    conn.commit()
    curr.execute("""select * from url_table where hash=md5(%s)::uuid and user_email = %s""",[str(url.url),credentials["email"]])
    result = curr.fetchone()
    curr.close()
    short_code = base62.encode(result[1])

    return {
        "url":str(request.base_url) + short_code
    }

@app.get("/{short_code}")
def getLong(short_code:str,response:Response,credentials : JwtAuthorizationCredentials = Security(access_security)):
    url_no = int(base62.decode(short_code))
    curr = conn.cursor()
    curr.execute("""select url from url_table where url_no = %s and user_email = %s""",[url_no,str(credentials["email"])])
    result = curr.fetchone()
    curr.close()
    if(not result):
        response.status_code = status.HTTP_404_NOT_FOUND
        return ResponseMessage(message="Not Found")
    
    return RedirectResponse(result[0],status_code=303)