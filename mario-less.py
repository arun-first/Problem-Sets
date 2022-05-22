# printing a pyramid of n size

# getting the size
def take_input():
    while True:
        n = int(input("Size: "))
        if n > 0:
            break
    return n

def pyramid(n):
    for i in range(0, n):
        for j in range(n - 1, i, -1):
            print(" ", end="")
        for k in range(0, i + 1):
            print("#", end="")
        print()

def main():
    n = take_input()
    pyramid(n)

# calling the main function
main()