#!/usr/bin/python3
"""the base which other classes inherit from"""

from datetime import datetime
import uuid

time = "%Y-%m-%dT%H:%M:%S.%f"


class BaseModel():
    """the base class"""
    def __init__(self, **kwargs):
        if kwargs:
            for k, v in kwargs.items():
                setattr(self, k, v)       

        self.id = str(uuid.uuid4())
        self.created_at = datetime.utcnow()
        self.updated_at = self.created_at
    
    def __str__(self):
        """called when printed"""
        return ("[{}] ({}) ({})".format(self.__class__.__name__, self.id, self.__dict__))

    def save(self):
        from storage import storage
        self.updated_at = datetime.utcnow()
        storage.new(self)
        storage.save()

    def to_dict(self):
        """returns a dict of the object"""
        my_dict = {}
        for k, v in self.__dict__.items():
            if k == 'created_at':
                my_dict[k] = self.__dict__['created_at'].strftime(time)
            elif k == 'updated_at':
                my_dict[k] = self.__dict__['updated_at'].strftime(time)
            else:
                my_dict[k] = v
        my_dict['class'] = self.__class__.__name__

        return my_dict

    def delete(self):
        from storage import storage
        storage.delete(self)
        storage.save()
