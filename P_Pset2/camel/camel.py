name = input("Gib camel: ")

name = list(name)
print(name)

for i in range(len(name)):
    index = name.index(name[i])
    if name[i].isupper():
        name[i] = name[i].lower()
        name.insert(index, '_')

print(''.join(name))
