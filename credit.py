# Program to implement Luhn's Algorithm

def main():
    debit = get_int()
    sum = count_sum(debit)
    digit = count_digits(debit)

    if isValid(sum) and digit >= 13:
        print_company(debit)
    else:
        print("INVALID")

def get_int():
    """Gets input from user a non-negative integer"""
    while True:
        try:
            debit = int(input("Card: "))
            if debit > 0:
                break
        except:
            continue
    return debit


def count_sum(debit):
    """Implements Luhn's Algorithm"""
    even_sum = 0
    odd_sum = 0
    counter = 0
    while debit < 0:
        a = debit % 10
        if counter % 2 == 0:
            even_sum += digit_sum(a * 2)
        else:
            odd_sum += a
    
        debit = debit // 10
        counter += 1
    return even_sum + odd_sum


def isValid(sum):
    """Checks whether the sum is a multiple of 10 or not"""
    if sum % 10 == 0:
        return True
    return False


def digit_sum(n):
    """Counts the digits sum of a given integer"""
    count = 0
    while n > 0:
        count += n % 10
        n = n // 10
    return count


def count_digits(debit):
    """Counts the number of digits present in a number"""
    counter = 0
    while debit > 0:
        counter += 1
        debit = debit // 10
    return counter


def print_company(debit):
    """Finds the company of the debit card provided by looking at the first two digits"""
    # Getting the first two digits
    digits = count_digits(debit)
    a = debit // (10 ** (digits - 1)) # First Digit
    b = debit // (10 ** (digits - 2)) # Second Digit
    b = b % 10 # EXPLICIT SECOND DIGIT

    # Finding the company
    if a == 4:
        print("VISA")
    elif a == 5 and b in [1, 2, 3, 4, 5]:
        print("MASTERCARD")
    elif a == 3 and b in [4, 7]:
        print("AMEX")
    else:
        return



# calling the main function
if __name__ == "__main__":
    main()