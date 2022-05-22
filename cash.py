# Program to simulate the greedy algorithm for Problem Set 6 of CS50

def main():
    """Main function to simulate the control flow"""
    change = take_input()
    coins = count_pennies(change)
    print(coins)


def take_input():
    """Takes input from the user, validates it and then returns it as a float"""
    while True:
        change = float(input("Change owed: "))
        if change > 0:
            return change


# list of avalaible pennies
money = [25, 10, 5, 1]

def count_pennies(change):
    """Counts the number of coins need to be spent in order to give the change"""
    coins = 0
    cents = change * 100 # converting into cents

    # comparing against the present values
    while cents > 0:
        if cents > money[0]:
            cents -= money[0]
        elif cents > money[1]:
            cents -= money[1]
        elif cents > money[2]:
            cents -= money[2]
        else:
            cents -= money[3]
        coins += 1
    return coins


# calling the main function
if __name__ == "__main__":
    main()
        
