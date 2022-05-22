# Program to demonstrate the Grading Scheme of a particular sentence or essay on the basis on Coleman-Liau Formula

def main():
    text = take_input()
    counts = []
    counts = count(text)
    index = calc_index(counts)
    print_grade(index)

def print_grade(index):
    """Prints the grade according to the index calculated"""
    if index <= 16 and index >= 1:
        print(f"Grade {index}")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade 16+")


def take_input():
    """Take input from the user a bunch of words or a para"""
    text = input("Text: ")
    text += " "
    return text


def count(text):
    """Counts the number of words, letters, sentences in a given string"""
    count = [0, 0, 0]
    for i in range(0, len(text)):
        a = text[i]
        if (a >= 'A' and a <= 'Z') or (a >= 'a' and a <= 'z'):
            count[0] += 1
        if (a == ',' or a == ' ' or a == '.' or a == '!') and not(text[i - 1] == ',' or text[i - 1] == '.' or text[i - 1] == '!'):
            count[1] += 1
        if a == '.' or a == '?' or a == '!':
            count[2] += 1
    return count

def calc_index(count):
    """Calculates the index of the string by calculating number of letter per 100 words and number of sentences per 100 words"""
    l_avg = count[0] / count[1] * 100
    s_avg = count[2] / count[1] * 100
    index = 0.0588 * l_avg - 0.296 * s_avg - 15.8
    return round(index)


# calling the main function
if __name__ == "__main__":
    main()