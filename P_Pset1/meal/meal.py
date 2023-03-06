def main():
    time = input("Gib time: ")
    time = convert(time)
    if 7 <= time <= 8:
        print("breakfast time")
    elif 12 <= time <= 13:
        print("lunch time")
    elif 18 <= time <= 19:
        print("dinner time")

def convert(time):
    hours, minutes = time.split(":")
    minutes = str(int(minutes) / 60)
    return int(hours) + float(minutes)

if __name__ == "__main__":
    main()
