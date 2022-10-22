from marshmallow import Schema,fields
from pkg_resources import require

class PlainItemSchema(Schema):
    id = fields.Str(dump_only=True)
    name = fields.Str(required=True)
    price = fields.Float(required=True)

class ItemUpdateSchema(Schema):
    name = fields.Str()
    price = fields.Float()
    store_id = fields.Int()

class PlainStoreSchema(Schema):
    id = fields.Str(dump_only=True)
    name= fields.Str(required=True)

class ItemSchema(PlainItemSchema):
    store_id = fields.Int(required=True,load_only=True)
    store = fields.Nested(PlainStoreSchema(),dump_only = True)

class StoreSchema(PlainStoreSchema):
    items = fields.List(fields.Nested(PlainItemSchema()),dump_only=True)
