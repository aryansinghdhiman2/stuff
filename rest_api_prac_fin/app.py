from email import message
import uuid
from flask import Flask,request
from flask_smorest import abort
from db import stores,items
app = Flask(__name__)


@app.get("/stores")
def get_stores():
    return {"stores": list(stores.values())}

@app.get("/stores/<string:store_id>")
def get_store(store_id):
    try:
        return stores[store_id]
    except KeyError:
        abort(404,message="Store not found.")

@app.post("/stores")
def create_stores():
    store_data = request.get_json()

    if("name" not in store_data):
        abort(400,message="Bad Request.Ensure name is included in JSON payload")
    
    for store in stores.values():
        if(store["name"]==
        store_data["name"]):
            abort(400,message="Store already exists")
    store_id = uuid.uuid4().hex
    new_store={**store_data,"id":store_id}
    stores[store_id]=new_store
    return new_store,201

@app.delete("/stores/<string:store_id>")
def delete_store(store_id):
    try:
        del stores[store_id]
        return {"message": "Store Deleted"}
    except KeyError:
        abort(404,message="Store not found.")


@app.get("/items")
def get_all_items():
    return {"items":list(items.values())}

@app.get("/items/<string:item_id>")
def get_item(item_id):
    try:
        return items[item_id]
    except KeyError:
        abort(404,message="Item not found.")

@app.post("/items")
def create_items():
    item_data = request.get_json()
    
    if(
        "price" not in item_data
        or "store_id" not in item_data
        or "name" not in item_data
    ):
        abort(400,
            message="Bad Request,Ensure 'price','store_id','name' are included in JSON payload")
    
    for item in items.values():
        if(
            item_data["name"]==item["name"]
            and 
            item_data["store_id"]==item["store_id"]
        ):
            abort(400,message="Item already exists")

    if(item_data["store_id"] not in stores):
        abort(404,message="Store not found.")
    item_id = uuid.uuid4().hex
    item = {**item_data,"id":item_id}
    items[item_id]=item
    return item,201

@app.put("/items/<string:item_id>")
def update_item(item_id):
    item_data=request.get_json()

    if(
        "name" not in item_data
        and "price" not in item_data
    ):
        abort(400,message="Bad Request.Ensure 'name' and 'price' exist in JSON payload")
    
    try:
        items[item_id] |= item_data
        return {"message":"Item updated"}
    except KeyError:
        abort(404,"Item not found")

@app.delete("/items/<string:item_id>")
def delete_item(item_id):
    try:
        del items[item_id]
        return {"message": "Item Deleted"}
    except KeyError:
        abort(404,message="Item not found.")


