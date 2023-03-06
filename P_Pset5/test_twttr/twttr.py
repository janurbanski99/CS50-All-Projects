def main():
    inp = input("Gib input: ")
    print(shorten(inp))



def shorten(word):
    vowels = ['a', 'e','i', 'o', 'u']
    sent2 = []

    for i in range(len(word)):
        if word[i].lower() not in vowels:
            sent2.append(word[i])

    return ''.join(sent2)

if __name__ == "__main__":
    main()