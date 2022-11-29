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
                if k != '__class__':
                    setattr(self, k, v)
        self.id = str(uuid.uuid4())
        self.created_at = datetime.utcnow()
        self.updated_at = self.created_at

    def __str__(self):
        """called when printed"""
        return ("[{}] ({}) ({})".format(self.__class__.__name__, self.id, self.__dict__))

    def save(self):
        from models.storage import storage
        self.updated_at = datetime.utcnow()
        storage.new(self)
        storage.save()

    def to_dict(self):
        """returns a dict of the object"""
        dictionary = {}
        for k, v in self.__dict__.items():
            if k == 'created_at':
                dictionary[k] = self.__dict__['created_at'].strftime(time)
            elif k == 'updated_at':
                dictionary[k] = self.__dict__['updated_at'].strftime(time)
            else:
                dictionary[k] = v
            dictionary['__class__'] = self.__class__.__name__
        return dictionary

    def update(self, **dictionary):
        from models.storage import storage
        for k, v in dictionary.items():
            setattr(self, k, v)
        storage.save()

    def delete(self):
        from models.storage import storage
        storage.delete(self)
        storage.save()
