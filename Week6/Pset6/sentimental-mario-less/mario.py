# TODO
from cs50 import get_int

while True:
    height = get_int("Gib height: ")
    if height >= 1 and height <= 8:
        for x in range(1, height + 1):
            print(" " * (height - x) + "#" * x)
        break
    else:
        print("Invalid output")
        continue
