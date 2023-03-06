import sys
from pyfiglet import Figlet
import random

figlet = Figlet()
fontlist = figlet.getFonts()


if len(sys.argv) == 3:
    if sys.argv[1] not in ['-f', '--font'] or sys.argv[2] not in fontlist:
        sys.exit("Invalid usage")
    inp = input("Input: ")
    figlet.setFont(font=sys.argv[2])
    print(figlet.renderText(inp))
elif len(sys.argv) == 1:
    inp = input("Input: ")
    figlet.setFont(font=random.choice(fontlist))
    print(figlet.renderText(inp))


