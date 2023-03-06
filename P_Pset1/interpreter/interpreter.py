exp = input("Gib expression: ")
x, y, z = exp.split(" ")
x, z = int(x), int(z)

if y == '+':
    result = float(x + z)
elif y == '-':
    result = float(x - z)
elif y == '*':
    result = float(x * z)
elif y == '/':
    result = float(x / z)

result = round(result, 1)
print(result)
