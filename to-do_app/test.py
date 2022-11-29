#!/usr/bin/python3

from models.task import Task

test1 = Task(name='test1')
test2 = Task(name='test2')


print(test1.to_dict())
print(test2.to_dict())
new_dict = {}
new_dict['title'] = 'Learn python'
new_dict['category_id'] = "e13d0fbe-c0ca-4341-bce4-e0d1a662769a"
new_dict['user_id'] = "f973a226-596b-4adf-ad91-333d56ae8795"

test1.update(**new_dict)
test1.save()
test2.save()
