#!/usr/bin/python3

import cmd
from models.storage import storage
from models.user import User
from models.task import Task
from models.category import Category


class TodoCommand(cmd.Cmd):
    prompt = '(todo) '
    classes = ['User', 'Task', 'Category']
    objs = storage.all()

    def do_quit(self, arg):
        return True

    def emptyline(self):
        pass

    def do_create(self,args):
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
            for k, v in storage.all().items():
                if line_arg[0] in k.split('.'):
                    all_objs.append(v.__str__())
        print(all_objs)


if __name__ == "__main__":
    TodoCommand().cmdloop()
