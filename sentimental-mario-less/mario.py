from cs50 import get_int

# TODO


def main():
    height = get_int("enter height: ")
    while height > 8 or height < 1:
        height = get_int("enter height: ")

    for i in range(1, height + 1):
        draw(i, height)


def draw(n, height):
    # Print spaces first
    spaces = height - n
    for i in range(spaces):
        print(" ", end="")

    # Then print '#' characters
    for i in range(n):
        print("#", end="")

    print("")


main()
