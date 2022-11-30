#!/usr/bin/python3

from models.base_models import BaseModel

class Task(BaseModel):
    name = ""
    description = ""
    completed = ""
    duration = ""
    category_id = ""
