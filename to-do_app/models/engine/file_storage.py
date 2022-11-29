#!/usr/bin/python3
"""This sets up a file storage for the objects"""
import json


class FileStorage:
    __objects = {}
    __filepath = "todo.json"

    def all(self, cls=None):
        if cls is None:
            return type(self).__objects
        else:
            temp = {}
            for key, val in type(self).__objects.items():
                if cls.__name__ in key:
                    temp[key] = val
            return temp

    def new(self, obj):
        new_key = obj.to_dict()['__class__'] + '.' + obj.id
        type(self).__objects[new_key] = obj

    def save(self):
        all_obj = {}
        for k, v in type(self).__objects.items():
            all_obj[k] = v.to_dict()
        with open(type(self).__filepath, 'w', encoding='utf-8') as f:
            json.dump(all_obj, f)

    def reload(self):
        from models.user import User
        from models.category import Category
        from models.task import Task
        try:
            with open(type(self).__filepath, 'r', encoding='utf-8') as f:
                content = json.load(f)

                for k, v in content.items():
                    if 'User' in k.split('.'):
                        prototype = User(**v)
                    elif 'Category' in k.split('.'):
                        prototype = Category(**v)
                    elif 'Task' in k.split('.'):
                        prototype = Task(**v)
                    type(self).__objects[k] = prototype
        except FileNotFoundError as e:
            pass

    def delete(self, obj):
        name = obj.__class__.__name__ + '.' + obj.id
        if name in type(self).__objects:
            del type(self).__objects[name]
