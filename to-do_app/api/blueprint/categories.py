#!/usr/bin/python3

from api.blueprint import app_views
from flask import abort, jsonify, make_response, request
from models.storage import storage
from models.task import Task
from models.category import Category
from models.user import User

@app_views.route('/category', strict_slashes=False, methods=['GET'])
def all_category():
    all_cat = []
    for k, v in storage.all(Category).items():
        all_cat.append(v.to_dict())

    return jsonify(all_cat)

@app_views.route('/category/<category_id>', strict_slashes=False, methods=['GET'])
def get_category(category_id):
    for k, v in storage.all(Category).items():
        if v.id == category_id:
            return jsonify(v.to_dict())
    abort(404)
