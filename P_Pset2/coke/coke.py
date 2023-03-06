price = 50
accepted = [25, 10, 5]
while price > 0:
    cash = int(input("Gib money: "))
    if cash not in accepted:
        continue
    price -= cash
    if price < 0:
        break
    else:
        print("Amount Due:", price)

print("Change Owed:", abs(price))