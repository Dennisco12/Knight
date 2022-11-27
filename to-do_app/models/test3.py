#!/usr/bin/python3

from task import Task
from user import User
from category import Category

test1 = User(name='Dennis')
test2 = Category(name='personal')

print('test1 has id of {}'.format(test1.id))
print('test2 has id of {}'.format(test2.id))

print('test1 was created on {}'.format(test1.created_at))

print(test1.to_dict())
test1.save()
test2.save()
