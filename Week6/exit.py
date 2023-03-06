import sys

if len(sys.argv) != 2:
    print("AAA")
    sys.exit(1)

print(f"Hemlo, {sys.argv[1]}")
sys.exit(0)     #jak się pobiera całą bibliotekę to wtedy trzeba nazwę biblioteki i kropkę (jak tylko jedną funkcję to tylko ta funkcja)