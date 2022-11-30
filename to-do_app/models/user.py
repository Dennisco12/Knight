#!/usr/bin/python3

from models.base_models import BaseModel


class User(BaseModel):
    username = ""
    password = ""
    email = ""
