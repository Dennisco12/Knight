#!/usr/bin/python3

from models.task import Task
from models.user import User
from models.category import Category

user2 = User(username='Dennis')
category2 = Category(name='general')

print('user2 has id of {}'.format(user2.id))
print('category2 has id of {}'.format(category2.id))

print()
print(user2.__dict__)
print(user2.to_dict())
user2.save()
category2.save()

new_dict = {}
new_dict['email'] = 'akinwonjowodennisco@gmail.com'
new_dict['password'] = 'Password123'
new_dict['category_id'] = category2.id

user2.update(**new_dict)
print()
print(user2)
