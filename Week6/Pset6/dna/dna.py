import csv
import sys
import random
import math


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: Usage: python dna.py csvfile textfile")

    d_base = []
    blacklisted_set = ("name")
    # TODO: Read database file into a variable - dictreader
    with(open(sys.argv[1], "r")) as database_file:
        reader1 = csv.DictReader(database_file)
        for person in reader1:
            d_base.append(person)
            for key, value in person.items():
                if key not in blacklisted_set:
                    person[key] = int(person[key])

    #print(reader.fieldnames[1::])
            #person["AGATC"] = int(person["AGATC"])

    # for dict in d_base:
    #     for key, value in dict.items():
    #         if key not in dict["name"]:
    #             value = int(value)
            #person[1:] = int(person)        #jeszcze przerobić na inty

    #print(d_base)

    seq = ''

    # TODO: Read DNA sequence file into a variable - reader
    with(open(sys.argv[2], "r")) as seq_file:
        reader2 = csv.reader(seq_file)
        for sequence in reader2:
            seq = sequence
    #print(seq)
    # TODO: Find longest match of each STR in DNA sequence
    longest_matches = []
    for STR in reader1.fieldnames[1::]:
        x = longest_match(str(seq), STR)
        longest_matches.append(x)


    #print(longest_matches)
    #print(d_base)

    # TODO: Check database for matching profiles
    for dict in d_base:
        strs = []
        for key, value in dict.items():
            strs.append(value)
        if longest_matches == strs[1::]:
            print(strs[0])
            return
    print("No match")

    #strs = []



    # for key, value in d_base[10].items():
    #     strs.append(value)

    # print(strs[1::])
    # print(longest_matches)
    # print(strs[1::] == longest_matches)


    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    #print(longest_run)
    return longest_run


main()
