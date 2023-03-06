def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if s[0:2].isalpha() and (2 <= len(s) <= 6) and nums(s):
        return True
    else:
        return False

def nums(s):
    for i in range(len(s)):
        try:
            if s[i].isnumeric() and s[i+1].isalpha():
                return False
            elif s[i].isalnum() == False:
                return False
            elif s[i] == '0' and s[i-1].isalpha():
                return False
        except IndexError:
            continue
    return True

main()

