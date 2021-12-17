
from colorama import Back

isExit = False
students = []

def printMsg(msg, mode):
    if mode == "SUCCESS":
        print(Back.GREEN + msg)
        print(Back.BLACK)
    elif mode == "ERROR":
        print(Back.RED + msg)
        print(Back.BLACK)
    elif mode == "INFO":
        print(Back.BLUE + msg)
        print(Back.BLACK)


def parseRollNo(val):
    return int(val)

def printMenu():
    print("1. Search Student Using Binary Search ")
    print("2. Search Student using Fibonacci Search ")
    print("3. Change Students in list")
    print("4. Exit")
def getStudents():
    global students
    students = list(map(parseRollNo, input("Enter roll no of students who attended training program(space after every rollno in sorted form):").split(" ")))
    if len(students) < 2:
        printMsg("Minimum 2 students required", "ERROR")
        getStudents()
    if not checkIfSorted():
        printMsg("Enterred roll no are not sorted. please enter sorted array!!", "ERROR")
        getStudents()


def checkIfSorted():
    asc = students[0] < students[1]
    if asc:
        for i in range(0, len(students)-1):
            if students[i] > students[i+1]:
                return False
        return True
    else:
        for i in range(0, len(students)-1):
            if students[i] < students[i+1]:
                return False
        return True

def binarySearch(ele):
    l = len(students)
    m = l//2
    if students[m] == ele:
        printMsg("Element Found at location " + str(m+1), "SUCCESS")
        return
    
    while m >= 0 and m < l:
        if students[m] == ele:
            printMsg("Element Found at location " + str(m+1), "SUCCESS")
            return
        if students[m] > ele:
            m -= 1
        else:
            m += 1

def getFibonacciSeries(arrLen):
    series = []
    first = 0
    second = 1
    nxt = first + second
    series.append(first)
    series.append(second)
    # series.append(nxt)
    while nxt <= arrLen:
        first = second
        second = nxt
        nxt = first + second
        series.append(nxt)
    print(series)

def fibonacciSearch(ele):
    pass

getStudents()
while not isExit:
    printMenu()
    printMsg("Enter Your Choice: ", "INFO")
    choice = int(input())
    if choice == 1:
        rollNo = int(input("Enter Roll no to search:"))
        binarySearch(rollNo)
    elif choice == 2:
        rollNo = int(input("Enter Roll no to search:"))
        # sentinalLinearSearch(rollNo)
        getFibonacciSeries(7)
    elif choice == 3:
        getStudents()
    elif choice == 4:
        isExit = True
    else:
        print("Invalid Choice!!!")