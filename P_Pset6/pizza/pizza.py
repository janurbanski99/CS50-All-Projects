import sys
import csv
from tabulate import tabulate

menu = []

if len(sys.argv) != 2 or sys.argv[1][-4:] != '.csv':
    sys.exit("Coś coś się popusuło")
else:
    try:
        with open(sys.argv[1]) as file:
            reader = csv.reader(file)
            for row in reader:
                menu.append(row)

        print(tabulate(menu, headers="firstrow", tablefmt="grid"))

    except FileNotFoundError:
        sys.exit("Coś coś się popsuło ale z file tym razem")

