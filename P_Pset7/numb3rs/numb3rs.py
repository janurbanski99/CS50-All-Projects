import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    matches = re.search(r"^([0-9]{1,3})\.([0-9]{1,3})\.([0-9]{1,3})\.([0-9]{1,3})$", ip)
    if matches:
        one, two, three, four = matches.groups()
        if int(one) in range(0, 256) and int(two) in range(0, 256) and int(three) in range(0, 256) and int(four) in range(0, 256):
            return True
        else:
            return False
    else:
        return False

if __name__ == "__main__":
    main()