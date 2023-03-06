from datetime import date
import re
import sys
import inflect

p = inflect.engine()

def main():
    birthday = check_date(input("Gib date: "))
    today = date.today()
    delta = (today - birthday)*24*60
    print(f"{(p.number_to_words(delta.days).capitalize()).replace(' and ', ' ')} minutes")

def check_date(data):
    matches = re.search(r"^([0-9]{4})-((?:[1][0-2])|(?:[0][0-9]))-((?:[0-2][0-9])|(?:[3][0-1]))$", data)
    if matches:
        year = int(matches.group(1))
        month = int(matches.group(2))
        day = int(matches.group(3))
        if (int(year) > date.today().year) or (int(year) == date.today().year and int(month) > date.today().month) or (
            int(year) == date.today().year and int(month) == date.today().month and int(day) > date.today().day):
            raise ValueError("Thats future date aaa")
        return date(year, month, day)
    else:
        sys.exit("Wrong format nibba")

if __name__ == "__main__":
    main()