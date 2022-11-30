#!/usr/bin/python3

from flask import abort, jsonify, request
from models.storage import storage
from api.blueprint import app_views
from models.user import User


@app_views.route('/users', strict_slashes=False, methods=['GET'])
def get_user():
    user_list = []
    for k, v in storage.all(User).items():
        user_list.append(v.to_dict())

    return jsonify(user_list)
