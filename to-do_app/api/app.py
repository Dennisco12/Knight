#!/usr/bin/python3

from flask import Flask, jsonify, abort, make_response
from models.storage import storage
from api.blueprint import app_views

app = Flask(__name__)
app.register_blueprint(app_views)
@app.errorhandler(404)
def not_found(error):
    return make_response(jsonify({'error': "Not found"}), 404)


if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000, threaded=True)
