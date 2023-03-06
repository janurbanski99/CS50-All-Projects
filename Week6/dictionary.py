words = set() #ekwiwalent hash table


def check(word):
    if word.lower() in words:
        return True
    else:
        return False


def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip() #dzieli linie na słowa osobne jak jest \n
        words.add(word)
    close(file)
    return True

def size():
    return len(words)


def unload():
    return True #bo Python sam zarządza pamięcią więc tu nic nie trzeba robić ^^
