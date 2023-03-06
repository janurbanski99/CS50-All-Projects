import csv

with open("phonebook2.csv", "a") as file:   #to taki skrót żeby nie musieć później pamiętać żeby zamknąć plik

    name = input("Gib name: ")
    number = input("Gib number: ")

    writer = csv.DictWriter(file, fieldnames = ["name", "number"])
    writer.writerow({"name": name, "number": number})

