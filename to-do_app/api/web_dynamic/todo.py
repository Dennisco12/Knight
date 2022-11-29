#!/usr/bin/python3

from flask import jsonify, abort, Flask, render_template
from models.storage import storage
from models.user import User
from models.category import Category
from models.task import Task

app = Flask(__name__)


@app.route('/todo/', strict_slashes=False)
def todo():
    categories = []
    tasks = []
    for k, v in storage.all(Task).items():
        tasks.append(v.to_dict())
    for k, v in storage.all(Category).items():
        categories.append(v)
    users = storage.all(User).values()
    username_list = []
    for user in users:
        username_list.append(user.username)

    return render_template('index.html',
                            tasks=tasks,
                            categories=categories,
                            users=username_list)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
