months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]
while True:
    date = input("Date: ")
    try:
        m, d, y = date.split('/')
        if m.isnumeric() == False or d.isnumeric() == False or y.isnumeric == False:
            continue
        m = int(m)
        d = int(d)
        if d > 31 or m > 12:
            continue
        print(f"{y}-{m:02}-{d:02}")
        break
    except ValueError:
        m, d, y = date.split(' ')
        d = d[0]
        if d.isnumeric() == False or m.isalpha() == False:
            continue
        d = int(d)
        if d > 31:
            continue
        if m in months:
            m = months.index(m) + 1
            print(f"{y}-{m:02}-{d:02}")
            break
        else:
            continue

