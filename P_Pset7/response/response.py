import validators

mail = input("Gib email: ")
if validators.email(mail):
    print('Valid')
else:
    print("Invalid")