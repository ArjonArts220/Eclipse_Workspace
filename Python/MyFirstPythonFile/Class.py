class Person:
    
    def __init__(self, name, age):
        print("constructor");
        
        self.name = name;
        self.age = age;
        
    def printPerson(self):
        print("Name: ", self.name, ", age: ", self.age);
        

class Man(Person):
    def __init__(self, name, age):
        print("constructor man");

        self.name = name;
        self.age = age;
                
    def changeName(self, newName):
        self.name = newName;

m = Man("Arjon", 20);
m.changeName("piet");
m.printPerson();