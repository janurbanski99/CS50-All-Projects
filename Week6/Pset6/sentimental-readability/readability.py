# TODO
from cs50 import get_string

text = get_string("Gib tekst: ")
text = text.lower()

letters = 0
words = 1
sentences = 0

for sign in text:
    if sign.isalpha():
        letters += 1

for sign in text:
    if sign == " ":
        words += 1

for sign in text:
    if sign == "." or sign == "?" or sign == "!":
        sentences += 1

index = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

