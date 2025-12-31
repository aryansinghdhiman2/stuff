from pydantic import BaseModel,AnyUrl,EmailStr

class User(BaseModel):
    email:EmailStr
    password:str

class ResponseMessage(BaseModel):
    message:str

class LongURL(BaseModel):
    url:AnyUrl

class AuthToken(BaseModel):
    token:str