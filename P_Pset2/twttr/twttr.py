vowels = ['a', 'e','i', 'o', 'u']

sent = input("Gib sth: ")
sent2 = []

for i in range(len(sent)):
    if sent[i].lower() not in vowels:
        sent2.append(sent[i])

print(''.join(sent2))