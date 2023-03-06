import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    matches = re.search(r"^([0-9][0-2]?):?([0-5][0-9])? (AM|PM) to ([0-9][0-2]?):?([0-5][0-9])? (AM|PM)$", s)
    if matches:
        hfrom = list(matches.group(1,2,3))
        hto = list(matches.group(4,5,6))
        if 'PM' in hfrom:
            hfrom[0] = int(hfrom[0]) + 12
        if 'PM' in hto:
            hto[0] = int(hto[0]) + 12
        if hfrom[1] == None:
            return f'{int(hfrom[0]):02}:00 to {int(hto[0]):02}:00'
        else:
            return f'{int(hfrom[0]):02}:{int(hfrom[1]):02} to {int(hto[0]):02}:{int(hto[1]):02}'
    else:
        raise ValueError


if __name__ == "__main__":
    main()


    # return f'{hfrom[0]} {hfrom[2]} to {hto[0]} {hto[2]}'
        # else:
        #     return f'{hfrom[0]}:{hfrom[1]} {hfrom[2]} to {hto[0]}:{hto[1]} {hto[2]}'