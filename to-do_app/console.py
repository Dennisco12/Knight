#!/usr/bin/python3

import cmd
from models.storage import storage
from models.user import User
from models.task import Task
from models.category import Category


class TodoCommand(cmd.Cmd):
    prompt = '(todo) '
    classes = {'User': User, 'Task': Task, 'Category': Category}
    objs = storage.all()

    def do_quit(self, arg):
        return True

    def emptyline(self):
        pass

    def do_create(self, args):
        if not args:
            print("class name missing")
            return False
        arg_list = args.split()
        if arg_list[0] not in type(self).classes:
            print("Invalid class name")
            return False
        if arg_list[0] == 'User':
            prototype = User()
        elif arg_list[0] == 'Task':
            prototype = Task()
        elif arg_list[0] == 'Category':
            prototype = Category()
        print(prototype.id)
        prototype.save()

    def do_all(self, args):
        all_objs = []
        if not args:
            for k, v in type(self).objs.items():
                all_objs.append(v.__str__())
        else:
            line_arg = args.split()
            if line_arg[0] not in type(self).classes:
                print("Invalid class")
                return False
            for k, v in type(self).objs.items():
                if line_arg[0] in k.split('.'):
                    all_objs.append(v.to_dict())
        print(all_objs)

    def do_update(self, args):
        if not args:
            print("Wetin u want make I update?")
            return False
        line_args = args.split()
        if line_args[0] not in type(self).classes:
            print("Invalid class")
            return False
        if len(line_args) < 2:
            print("Enter a class id")
            return False
        elif len(line_args) < 3:
            print("Enter an attribute key")
            return False
        elif len(line_args) < 4:
            print("Enter an attribute value")
            return False
        search_key = line_args[0] + '.' + line_args[1]
        search_class = type(self).classes[line_args[0]]
        if search_key in storage.all():
            for k, obj in type(self).objs.items():
                if k == search_key:
                    key = line_args[2]
                    value = line_args[3]
                    obj.__dict__[key] = value
                    storage.save()
        else:
            print("Object not found")
            return False



if __name__ == "__main__":
    TodoCommand().cmdloop()
