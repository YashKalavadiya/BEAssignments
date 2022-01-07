
percentage = []

def parsePer(per):
    return float(per)

def printMenu():
    print("MENU")
    print("1. Insertion sort")
    print("2. Shell sort")
    print("3. EXIT")

def insertionSort(tempArr):
    # tempArr = percentage
    for i in range(1, len(tempArr)):
        swapTerm = tempArr[i]
        j = i - 1
        while j >= 0 and swapTerm <= tempArr[j]:
            tempArr[j+1] = tempArr[j]
            j -= 1
        tempArr[j+1] = swapTerm
    print("Array sorted using insertion sort is: ", tempArr)
    return tempArr

def shellSort(tempArr):
    n = len(tempArr)
    gap = n//2
    while gap > 0:
        for i in range(gap, n):
            temp = tempArr[i]

            j = i
            while j >= gap and tempArr[j-gap] > temp:
                tempArr[j] = tempArr[j-gap]
                j -= 1
            tempArr[j] = temp
        gap = gap//2
    print("Sorted using Shell sort: ", tempArr)



def main():
    isExit = False
    global percentage
    percentage = list(map(parsePer, input("Enter percentages to sort(seperate by space): ").split(" ")))
    while not isExit:
        printMenu()
        ch = int(input("Enter your choice: "))
        if ch == 1:
            insertionSort(percentage)
        elif ch == 2:
            shellSort(percentage)
        elif ch == 3:
            isExit = True
        else:
            print("Invalid Choice")

main()