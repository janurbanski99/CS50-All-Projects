#from cs50 import get_int

# while True:
#     n = get_int("Gib height: ")
#     if n > 0:
#         break

# for i in range(n):
#     print("#")

def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        try:
            n = int(input("Gib height: "))
            if n > 0:
                return n
                    #mimo że n jest zmienną lokalną to python pamięta jej wartość też poza pętlą while - może być też po prostu return zamiast break to wtedy automatycznie się wyjdzie z pętli
        except ValueError:
            print("Not int")

main()