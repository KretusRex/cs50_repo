# TODO
from cs50 import get_string


def main():
    input = get_string("Enter text to evaluate: ")
    count_characters(input)


def count_characters(text):
    # Initialize counters
    words = 1
    letters = 0
    sentences = 0

    # Iterate through the characters in the text
    for char in text:
        if char.isspace():  # Check for spaces
            words += 1
        elif char.isalpha():  # Check for letters
            letters += 1
        elif char == "." or char == "!" or char == "?":  # Check for sentence breakers
            sentences += 1
    # print(str(letters) + " " + str(words) + " " + str(sentences))
    calc_complex(letters, words, sentences)


def calc_complex(letters, words, sentences):
    # L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    # print(str(L) + " " + str(S))
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print("Grade " + str(round(index)))

    return


main()
