from flask import Flask,render_template

app = Flask(__name__)

@app.route("/")
def my_home():
    return render_template("index.html")

@app.route("/<string:page_name>")
def work_route(page_name):
    return render_template(page_name)

# @app.route("/<username>")
# def hello_world_2(username):
#     return render_template("name.html",name=username)

@app.route('/submit_form', methods=['POST', 'GET'])
def submit_form():
    return "form submitted!"