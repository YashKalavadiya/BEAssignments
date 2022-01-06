
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

# def binarySearch(ele):
#     l = len(students)
#     m = l//2
#     if students[m] == ele:
#         printMsg("Element Found at location " + str(m+1), "SUCCESS")
#         return
#     f = 0
#     while m >= f and m < l:
#         if students[m] == ele:
#             printMsg("Element Found at location " + str(m+1), "SUCCESS")
#             return
#         if students[m] > ele:
#             l = m-1
#         else:
#             f = m + 1
#         m = (f + l)//2
#     printMsg("Element Not Found ", "ERROR")

def binarySearch(i, j, inputList, key):
    mid = (i+j) // 2
    if inputList[mid] == key:
        return mid
    elif i >= j:
        return -1
    elif (key > inputList[mid]):
        return binarySearch(mid+1, j, inputList, key)
    elif (key < inputList[mid]):
        return binarySearch(i, mid-1, inputList, key)

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
    return series

def fibonacciSearch(ele):
    studLen = len(students)
    series = getFibonacciSeries(studLen)
    k = len(series)-1
    ofs = -1
    while k > 0:
        i = min(ofs + series[k-2], studLen-1)
        if ele == students[i]:
            printMsg("Element found at location " + str(i), "SUCCESS")
            return
        elif ele > students[i]:
            ofs = i
            k -= 1
        else:
            k -= 1
    printMsg("Element Not Found", "ERROR")
    return


getStudents()
while not isExit:
    printMenu()
    printMsg("Enter Your Choice: ", "INFO")
    choice = int(input())
    if choice == 1:
        rollNo = int(input("Enter Roll no to search:"))
        result = binarySearch(0, len(students)-1, students, rollNo)
        if result == -1:
            printMsg("Element Not Found ", "ERROR")
        else:
            printMsg("Element Found at index " + str(result), "SUCCESS")
    elif choice == 2:
        rollNo = int(input("Enter Roll no to search:"))
        # sentinalLinearSearch(rollNo)
        fibonacciSearch(rollNo)
    elif choice == 3:
        getStudents()
    elif choice == 4:
        isExit = True
    else:
        print("Invalid Choice!!!")