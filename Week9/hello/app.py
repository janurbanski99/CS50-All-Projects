from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"]) #jak tu jest / to to znaczy że to ta 1 strona która się otwiera
def index():
    if request.method=="GET":
        return render_template("index.html")#, name=name)
    elif request.method=="POST":
        return render_template("greet.html", name=request.form.get("name", "world"))
    # name = request.args.get("name", "world") #get nie da nam błędu jak nie bd nic wpisane i domyślnie niech da world
    # dłuższa werjsa:
    # if "name" in request.args:
    #     name = request.args["name"]
    # else:
    #     name = "world"


# @app.route("/greet")
# def greet():
#     return render_template("greet.html", name = request.args.get("name", "world")) #to name= może być też w osobnej linii wyżej jak wcześniej

