#!/usr/bin/python3

from models.task import Task
from models.user import User
from models.category import Category

user2 = User(username='Dennis')
category2 = Category(name='general')

print()
user2.save()
category2.save()

new_dict = {}
new_dict['email'] = 'akinwonjowodennisco@gmail.com'
new_dict['password'] = 'Password123'

dict_2 = {}
dict_2['user_id'] = user2.id
dict_2['description'] = "This contains all my general tasks"

user2.update(**new_dict)
category2.update(**dict_2)
print()
print(user2)
print(category2)
