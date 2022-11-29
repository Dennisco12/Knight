#!/usr/bin/python3

from models.storage import storage
from models.task import Task

if __name__ == "__main__":
    cats = []
    for k, v in storage.all(Task).items():
        cats.append(v.to_dict())
    print(cats)
