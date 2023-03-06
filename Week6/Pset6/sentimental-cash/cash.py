# TODO
from cs50 import get_float

def main():
    dollars = get_dollars()

    quarters = calculate_quarters(dollars)
    dollars = round(dollars - quarters * 0.25, 3)

    dimes = calculate_dimes(dollars)
    dollars = round(dollars - dimes * 0.1, 3)

    nickels = calculate_nickels(dollars)
    dollars = round(dollars - nickels * 0.05, 3)

    pennies = calculate_pennies(dollars)
    dollars = round(dollars - pennies * 0.01, 3)

    coins = quarters + dimes + nickels + pennies
    # print(f"quarters: {quarters}")
    # print(f"dimes: {dimes}")
    # print(dollars)
    # print(f"nickels: {nickels}")
    # print(f"pennies: {pennies}")

    print(int(coins))


def get_dollars():
    num_dollars = 0
    while num_dollars <= 0:
        num_dollars = get_float("How much dollars do u owe?: ")
    return num_dollars

def calculate_quarters(dollars):
    if dollars < 0.25:
        return 0
    else:
        return int(dollars / 0.25)

def calculate_dimes(dollars):
    if dollars < 0.1:
        return 0
    else:
        return int(dollars / 0.1)

def calculate_nickels(dollars):
    if dollars < 0.05:
        return 0
    else:
        return int(dollars / 0.05)

def calculate_pennies(dollars):
    return int(dollars / 0.01)


main()