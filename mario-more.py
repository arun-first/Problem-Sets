def main():
    h = get_int()
    for i in range(0, h):
        # Printing the first inverted pyramid
        for j in range(h, i, -1):
            print(" ", end = "")
        for k in range(0, i + 1):
            print("#", end = "")
        for j in range(0, 2):
            print(" ", end = "")
        for j in range(0, i + 1):
            print("#", end = "")
        print()
        

def get_int():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                break
        except:
            continue
    return n
main()