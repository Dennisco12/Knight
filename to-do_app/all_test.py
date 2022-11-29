#!/usr/bin/python3

from models.storage import storage
from models.category import Category

if __name__ == "__main__":
    cats = []
    for k, v in storage.all(Category).items():
        cats.append(v.to_dict)
    print(cats)
