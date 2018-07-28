class Animal(object):
    """Makes cute animals."""

    # global attribute
    is_alive = True

    def __init__(self, name, age):
        # local attribute
        self.name = name
        self.age = age
        
    # method 
    def description(self):
        print self.name
        print self.age

class Cat(Animal):
    """inheritance"""
    def __init__(self, name, age):
        Animal.__init__(self, name, age)
        self.isCute = True

    def description(self):
        super(Cat, self).description()
        print self.isCute

hippo = Animal("A", 18)
print hippo.description()
cat = Cat("C", 11)
print cat.description()
