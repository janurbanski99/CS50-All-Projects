while True:
    try:
        fraction = input("Gib fuel as X/Y: ")
        x, y = fraction.split("/")
        x = int(x)
        y = int(y)
        result = x / y * 100
        if result <= 1:
            print('E')
        elif x > y:
            continue
        elif result >= 99:
            print('F')
        else:
            print(str(result)[0:2] + "%")
        break
    except ZeroDivisionError:
        print("ZerroDivisionError aaa")
    except ValueError:
        print("ValueError aaa")