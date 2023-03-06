import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    matches = re.search(r'^.*"https?://(?:www\.)?youtube\.com/embed/(\w+)".*$', s)
    if matches:
        url = matches.group(1)
        # print(url)
        if url == '':
            return None
        else:
            return f'https://youtu.be/{url}'


if __name__ == "__main__":
    main()