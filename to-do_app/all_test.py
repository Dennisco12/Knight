#!/usr/bin/python3

from models.storage import storage
from models.category import Category
from models.user import User
from models.task import Task


if __name__ == "__main__":
    user1 = User()
    category1 = Category()
    category2 = Category()
    task1 = Task()
    task2 = Task()
    task3 = Task()
    task4 = Task()

    user_dict = {'username': 'Dennis',
                 'email': 'akinwonjowodennisco@gmail.com',
                 'password': 'Password123'}
    category_dict = {
            'name': 'General',
            'description': "This contains the life things I need to do",
            'user_id': user1.id}
    category2_dict = {
            'name': "School",
            'description': "This contains all the things I need to do in school",
            'user_id': user1.id}
    task_dict = {
            'title': "Learn Python",
            'description': "To become the best software engineer, the knowledge\
            of python is neccessary. Learn that language today",
            'category_id': category2.id,
            'user_id': user1.id}
    task2_dict = {
            'title': "Buy clothes",
            'description': "Wearing good clothes gives a lot of confidence,\
            Ensure you invest your money on your dressing",
            'category_id': category1.id,
            'user_id': user1.id}
    task3_dict = {
            'title': "Write Report",
            'description': "A school report for my SIWES, It must be at least\
             45 pages",
            'category_id': category2.id,
            'user_id': user1.id}
    task4_dict = {
            'title': "Buy Earrings",
            'description': "Your girlfriend has tried enough, get her a piece of jewel,\
            girls love that shit",
            'category_id': category1.id,
            'user_id': user1.id}

    user1.update(**user_dict)
    category1.update(**category_dict)
    category2.update(**category2_dict)
    task1.update(**task_dict)
    task2.update(**task2_dict)
    task3.update(**task3_dict)
    task4.update(**task4_dict)

    user1.save()
    category1.save()
    category2.save()
    task1.save()
    task2.save()
    task3.save()
    task4.save()
