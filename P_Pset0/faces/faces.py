def convert(text):
    text = text.replace(":)", "🙂")
    text = text.replace(":(", "🙁")
    return text

def main():
    sent = input("Gib text with :) or :( ")
    sent2 = convert(sent)
    print(sent2)

main()