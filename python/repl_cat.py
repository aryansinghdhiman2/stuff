#Given the below class:
class Cat:
    species = 'mammal'
    def __init__(self, name, age):
        self.name = name
        self.age = age


# 1 Instantiate the Cat object with 3 cats
cat_1=Cat("Ron",6)
cat_2=Cat("Tom",4)
cat_3=Cat("Rob",9)


# 2 Create a function that finds the oldest cat
def oldest_cat(cat_1,cat_2,cat_3):
    if(cat_1.age>cat_2.age):
        if(cat_1.age>cat_3.age):
            print(f"{cat_1.name} is the oldest cat")
        else:
            print(f"{cat_3.name} is the oldest cat")
        
    else:
        if(cat_2.age()>cat_3.age()):
            print(f"{cat_2.name} is the oldest cat")
        else:
            print(f"{cat_3.name} is the oldest cat")




# 3 Print out: "The oldest cat is x years old.". x will be the oldest cat age by using the function in #2
oldest_cat(cat_1,cat_2,cat_3)

