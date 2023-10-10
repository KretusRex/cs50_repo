import csv
import sys
import copy


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")
    # TODO: Read database file into a variable
    database = []

    with open(sys.argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            data = {"name": row["name"]}
            for field in reader.fieldnames:
                if field != "name":
                    data[field] = int(row[field])

            database.append(data)

    # TODO: Read DNA sequence file into a variable

    f = open(sys.argv[2], "r")
    dna_seq = f.readline()
    f.close()

    # TODO: Find longest match of each STR in DNA sequence
    dna = {}
    for key in data.keys():
        # this bit is quite important - it sends each of dictionary's entries to the function to search for subsequences
        if key != "name":
            seq_match = longest_match(dna_seq, key)
            # the key here is the magic bit from dictionary - it helps determine what the longest_match function is seraching for
            dna[key] = seq_match

    # TODO: Check database for matching profiles

    match = True
    for person in database:
        person_copy = copy.deepcopy(person)
        # copying the content of the database entry to the new dictionary
        del person_copy["name"]
        # removing "name" from the dictionary to speed up comparison process
        for key in person_copy:
            # comparison begins
            if person_copy[key] != dna[key]:
                match = False
                break
            else:
                match = True

        if match == True:
            print(person["name"])
            return
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    current_run = 0
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    i = 0

    while i < sequence_length - subsequence_length + 1:
        # my trick to sequence the DNA
        if sequence[i: i + subsequence_length] == subsequence:
            # checking for subsequences appearing in the database and comparing each slice of dna
            current_run += 1
            i += subsequence_length
            # and if found moves cursor to the next character after the subsequence found to see if another repetition of subsequence starts
            if current_run > longest_run:
                longest_run = current_run
        else:
            current_run = 0
            i += 1
            # it the match is not found, then cursor moves only by one character

    return longest_run


main()
