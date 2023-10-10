# TODO
from cs50 import get_float


def main():
    cents = get_float("Change owed: ") * 100
    while cents < 0:
        cents = get_float("Change owed: ")

    # Calculate the number of quarters to give the customer
    quarters = calc_quart(cents)
    cents = cents - quarters * 25
    # print("quarters: " + str(quarters))

    # Calculate the number of dimes to give the customer
    dimes = calc_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the number of nickels to give the customer
    nickels = calc_nick(cents)
    cents = cents - nickels * 5

    # Calculate the number of pennies to give the customer
    pennies = calc_pen(cents)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)


def calc_quart(cents):
    quarters = int(cents / 25)
    return quarters


def calc_dimes(cents):
    dimes = int(cents / 10)
    return dimes


def calc_nick(cents):
    nickels = int(cents / 5)
    return nickels


def calc_pen(cents):
    pennies = int(cents)
    return pennies


main()
