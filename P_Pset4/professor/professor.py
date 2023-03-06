import random


def main():
    lvl = get_level()
    for x in range(1,11):
        x = generate_integer(lvl)
        y = generate_integer(lvl)
        sol = x + y
        tries = 3
        while tries > 0:
            try:
                answer = input(f"{x} + {y} = ")
                if int(answer) != sol:
                    print("EEE")
                    tries -= 1
                    if tries == 0:
                        print(sol)
                    continue
                else:
                    break
            except ValueError:
                tries -= 1
                print("EEE")
                continue

def get_level():
    while True:
        try:
            level = int(input("Level: "))
            if level not in [1,2,3]:
                continue
            return level
        except ValueError:
            continue

def generate_integer(level):
    if level == 1:
        return random.randint(0,9)
    elif level == 2:
        return random.randint(10,99)
    elif level == 3:
        return random.randint(100,999)


if __name__ == "__main__":
    main()