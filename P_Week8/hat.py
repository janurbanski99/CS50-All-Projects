import random

class Hat:
    houses = ['G', 'H', 'R', 'S']

    @classmethod
    def sort(cls, name):
        house = random.choice(cls.houses)
        print(name, 'is in', house)

Hat.sort("Harry")