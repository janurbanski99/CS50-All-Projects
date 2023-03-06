names = []

while True:
    try:
        name = input("Name: ")
        names.append(name)
    except (EOFError, KeyboardInterrupt):
        print()
        names1 = names[0:-1]
        names2 = names[-1]
        break
print("Adieu, adieu, to",', '.join(names1) +',', 'and', (names2))
