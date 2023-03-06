import emoji

inp = input("Input: ")

inp = emoji.emojize(f'{inp}', language='alias')
print(inp)