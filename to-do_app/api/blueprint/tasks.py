#!/usr/bin/python3

from api.blueprint import app_views
from models.storage import storage
from models.task import Task
from models.category import Category
from flask import jsonify, abort, request, make_response

@app_views.route('/tasks', strict_slashes=False, methods=['GET'])
def all_tasks():
    """Returns a list of all tasks"""
    task_list = []
    for k, v in storage.all(Task).items():
        task_list.append(v.to_dict())
    return jsonify(task_list)

@app_views.route('/category/<category_id>/tasks', strict_slashes=False,
                 methods=['GET'])
def cat_tasks(category_id):
    """Returns a list of all tasks in a category"""
    cat_tasks = []
    for k, v in storage.all(Task).items():
        if v.category_id == category_id:
            cat_tasks.append(v.to_dict())
    if len(cat_tasks) == 0:
        abort(404, "Category not found")
    return jsonify(cat_tasks)

@app_views.route('/tasks/<task_id>', strict_slashes=False, methods=['GET'])
def get_task(task_id):
    """Returns a specific task"""
    for k, v in storage.all(Task).items():
        if v.id == task_id:
            return jsonify(v.to_dict())
    abort(404, "Task not found")

@app_views.route('/users/<user_id>/tasks', strict_slashes=False,
                 methods=['GET'])
def user_task(user_id):
    """Returns a list of tasks for a specific user"""
    user_tasks = []
    for k, v in storage.all(Task).items():
        if v.user_id == user_id:
            user_tasks.append(v.to_dict())
    if len(user_task) == 0:
        abort(404)
    return jsonify(user_tasks)

@app_views.route('/tasks', strict_slashes=False, methods=['POST'])
def create_task():
    cat_id = []
    for k, v in storage.all(Category).items():
        cat_id.append(v.id)

    if not request.json:
        abort(400, "Not a JSON")
    elif 'category_id' not in request.json:
        abort(400, "No selcted category")
    elif 'user_id' not in request.json:
        abort(400, "No selected user")
    request_dict = request.get_json()
    prototype = Task(**request_dict)
    prototype.save()
    return make_response(jsonify(prototype.to_dict()))
