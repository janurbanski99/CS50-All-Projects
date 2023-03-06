import sys

counter = 0

if len(sys.argv) != 2 or sys.argv[1][-3:] != '.py':
    sys.exit("Coś coś się popusuło")
else:
    try:
        with open(sys.argv[1]) as file:
            for line in file:
                if line.lstrip().startswith('#') or line.strip() == '':
                    pass
                else:
                    counter += 1

        print(counter)
    except FileNotFoundError:
        sys.exit("Coś coś się popsuło ale z file tym razem")

