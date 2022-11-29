#!/usr/bin/python3

from models.task import Task

test3 = Task(name='test3')

print('test3 has id of {}'.format(test3.id))

print('test3 was created on {}'.format(test3.created_at))

print(test3.to_dict())
test3.save()
