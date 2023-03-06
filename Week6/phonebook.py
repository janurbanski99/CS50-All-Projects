people = {
    "Carter": "123",
    "David": "456"
}

name = input("Gib name: ")
if name in people:
    print(f"Number: {people[name]}")        #więc tutaj printujemy po prostu wartość jaka jest przy danym imieniu (bo imię to klucz, a numer - wartość)
