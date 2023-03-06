menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

price = 0

while True:
    try:
        order = input(':').title()
        if order in menu:
            price += menu[order]
        print(f"${price:.2f}")
    except (EOFError, KeyboardInterrupt):
        print()
        print(f"${price:.2f}")
        break