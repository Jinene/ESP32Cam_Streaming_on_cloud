from flask import Flask, request, send_from_directory
import os
from datetime import datetime

app = Flask(__name__)
UPLOAD_FOLDER = "uploads"

if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

@app.route("/upload_frame", methods=["POST"])
def upload_frame():
    frame = request.data
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S%f") + ".jpg"
    with open(os.path.join(UPLOAD_FOLDER, timestamp), "wb") as f:
        f.write(frame)
    return "OK", 200

@app.route("/")
def index():
    return send_from_directory("static", "index.html")

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
