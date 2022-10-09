from flask import Flask
from flask_restful import Api,Resource

app = Flask(__name__)
api = Api(app)

class HelloWorld(Resource):
    def get(self,name):
        return {"Data":"Hello "+name}

api.add_resource(HelloWorld,"/helloworld/<string:name>")

@app.route('/')
def getmain():
    return "Main page"
