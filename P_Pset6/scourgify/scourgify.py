import sys
import csv

students = []

if len(sys.argv) != 3:
    sys.exit("Coś coś się popusuło")
else:
    try:
        with open(sys.argv[1]) as file:
            reader = csv.DictReader(file)
            for row in reader:
                last, first = row['name'].split(', ')
                students.append({'first': first, 'last': last, 'house': row['house']})
                # students.append({'first': row['name'].split(', ')[1], 'last': row['name'].split(', ')[0], 'house': row['house']})

        with open(sys.argv[2], 'w') as file2:
            writer = csv.DictWriter(file2,fieldnames = ["first", "last", "house"])
            writer.writeheader()
            for student in students:
                writer.writerow({"first": student['first'], "last": student["last"], "house": student["house"]})

    except FileNotFoundError:
        sys.exit("Coś coś się popsuło ale z file tym razem")

