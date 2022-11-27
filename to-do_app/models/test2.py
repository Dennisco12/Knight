#!/usr/bin/python3

from task import Task

test3 = Task(name='test3')
test4 = Task(name='test3')

print('test3 has id of {}'.format(test3.id))
print('test4 has id of {}'.format(test4.id))

print('test3 was created on {}'.format(test3.created_at))

print(test3.to_dict())
test3.save()
test3.save()

test4.delete()
