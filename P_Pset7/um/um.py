import re
import sys


def main():
    print(count(input("Text: ")))


def count(s):
    counter = 0
    s = s.lower()

    s = re.sub(r"\?|!|\.|,|-", "", s)

    s = s.split()

    for el in s:
        if el == 'um':
            counter += 1
    # print(s)
    return counter

if __name__ == "__main__":
    main()