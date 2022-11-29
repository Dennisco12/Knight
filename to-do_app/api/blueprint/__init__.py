#!/usr/bin/python3

from flask import Blueprint

app_views = Blueprint('app_views', __name__, url_prefix='/api')

from api.blueprint.categories import *
from api.blueprint.tasks import *
