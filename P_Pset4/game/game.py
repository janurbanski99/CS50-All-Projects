import random
import sys

while True:
    try:
        level = int(input("Level: "))
        if level < 1:
            continue
        num = random.randint(1, level)
        print(num)
        while True:
            try:
                guess = int(input("Guess: "))
                if guess < 1:
                    continue
                elif guess > num:
                    print("Too large!")
                elif guess < num:
                    print("Too small!")
                else:
                    sys.exit("Just right!")
            except ValueError:
                continue
    except ValueError:
        continue