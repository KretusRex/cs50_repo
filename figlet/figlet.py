from pyfiglet import Figlet
import sys
import random

figlet = Figlet()


def main():
    if len(sys.argv) == 3:
        if sys.argv[1] == "-f" or sys.argv[1] == "--font":
            font_chk(sys.argv[2])
        elif sys.argv[1] != "-f" or sys.argv[1] != "--font":
            print("Invalid usage")
            sys.exit(1)
    elif len(sys.argv) == 2 or len(sys.argv) > 3:
        print("usage: figlet.py -f font")
        sys.exit(3)
    else:
        text_gen(random.choice(figlet.getFonts()))


def font_chk(usr_font):
    if usr_font in figlet.getFonts():
        text_gen(usr_font)
    else:
        print("font not found")
        sys.exit(2)

def text_gen(usr_font):
    figlet.setFont(font = usr_font)
    usr_input = input("Input: ")
    print(figlet.renderText(usr_input))

main()
