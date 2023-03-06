def main():
    try:
        inp = input("Gib: ")
        inp = convert(inp)
        print(gauge(inp))
    except TypeError:
        print('dupa')


def convert(fraction):
    x, y = fraction.split("/")
    try:
        x = int(x)
        y = int(y)
        if y == 0:
            raise ZeroDivisionError
        if x > y:
            raise ValueError
        result = x / y * 100
        return result
    except ValueError:
        print('ValueError')
        raise
        return 'dupa'

    except ZeroDivisionError:
        print("ZerroDivisionError")
        raise
        return 'dupa'

def gauge(percentage):
    try:
        if percentage <= 1:
            return 'E'
        elif percentage >= 99:
            return 'F'
        else:
            return str(percentage)[0:2] + "%"
    except (ValueError, ZeroDivisionError):
        return 'dupa'


if __name__ == "__main__":
    main()