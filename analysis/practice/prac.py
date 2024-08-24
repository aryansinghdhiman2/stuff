class person():
    def __init__(self,time):
        self.time=time
    def __lt__(self,__o:'person'):
        if(self.time<__o.time):
            return True
        else: return False

def bridgeAndTorch(persons:list[person]):
    persons.sort()
    passedTime=0
    runner=persons[0]
    persons.pop(0)
    while(persons):
        if(len(persons)==1):
            passedTime+=persons[0].time
            persons.pop(0)
        else:
            passedTime+=persons[0].time+runner.time
            persons.pop(0)
    return passedTime

# a=person()
per=[person(1),person(2),person(5),person(8)]
# per=[person(10),person(20),person(30)]
print(bridgeAndTorch(per))

