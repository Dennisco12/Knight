#!/usr/bin/python3

from task import Task

test1 = Task(name='test1')
test2 = Task(name='test2')

print('test1 has id of {}'.format(test1.id))
print('test2 has id of {}'.format(test2.id))

print('test1 was created on {}'.format(test1.created_at))

print(test1.to_dict())
test1.save()
test2.save()

test1.delete()
