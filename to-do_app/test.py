#!/usr/bin/python3

from models.task import Task

test1 = Task(name='test1')
test2 = Task(name='test2')


print(test1.to_dict())
print(test2.to_dict())
new_dict = {}
new_dict['title'] = 'Learn python'
new_dict['category_id'] = "fd69a6d1-e475-405d-9a2e-e4c60b7e1943"
new_dict['user_id'] = "f7b7398b-ea1c-4015-9907-b01fa7c808a9"
new_dict['description'] = "To become a great software engineer, the knowledge of python is extremely important. make sure to learn the great language"

dict_2 = {}
dict_2['title'] = 'Write Report'
dict_2['category_id'] = "fd69a6d1-e475-405d-9a2e-e4c60b7e1943"
dict_2['description'] = "I have to write my SIWES report and it must be nothing less than 45 pages"
dict_2['user_id'] = "f7b7398b-ea1c-4015-9907-b01fa7c808a9"

test1.update(**new_dict)
test2.update(**dict_2)
test1.save()
test2.save()
