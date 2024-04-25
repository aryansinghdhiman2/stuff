from fastapi import FastAPI
from typing import Any
from pydantic import BaseModel

app = FastAPI()

class DeviceData(BaseModel):
    id:int
    numbers : int

@app.get("/")
def hello() -> dict[str,str]:
    return {"Message":"Hello"}

@app.post("/data/",status_code=200)
def print_data(data:DeviceData):
    print(data)