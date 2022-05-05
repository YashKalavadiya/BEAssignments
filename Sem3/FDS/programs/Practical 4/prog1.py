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
    print("1. Search Student Using Linear Search ")
    print("2. Search Student using sentinal Search ")
    print("3. Change Students in list")
    print("4. Exit")
def getStudents():
    global students
    students = list(map(parseRollNo, input("Enter roll no of students who attended training program(space after every rollno):").split(" ")))
    if len(students) < 2:
        printMsg("Minimum 2 students required", "ERROR")
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


def linearSearchStudents(rollNo):
    count = 0
    if checkIfSorted():
        printMsg("This array is alredy sorted, try to run binnary search program for more efficiency!!", "ERROR")
        return False
    for stud in students:
        if int(stud) == rollNo:
            # print("Student attended training program and is located at index: ", count)
            printMsg("Student attended training program and is located at index: " + str(count), "SUCCESS")
            return True
        count += 1
    printMsg("No, Student did not attend the training program", "ERROR")
    return False

def sentinalLinearSearch(rollNo):
    if checkIfSorted():
        printMsg("This array is alredy sorted, try to run binnary search program for more efficiency!!", "ERROR")
        return False
    last = students[-1]
    students[-1] = rollNo
    idx = 0
    while(students[idx] != rollNo):
        idx += 1
    students[-1] = last
    if idx < len(students)-1 or students[-1] == rollNo:
        printMsg("Found Student using sentinal search", "SUCCESS")
        return False
    printMsg("Student Not Found", "ERROR")
    return False
    


getStudents()
while not isExit:
    printMenu()
    printMsg("Enter Your Choice: ", "INFO")
    choice = int(input())
    if choice == 1:
        rollNo = int(input("Enter Roll no to search:"))
        linearSearchStudents(rollNo)
    elif choice == 2:
        rollNo = int(input("Enter Roll no to search:"))
        sentinalLinearSearch(rollNo)
    elif choice == 3:
        getStudents()
    elif choice == 4:
        isExit = True
    else:
        print("Invalid Choice!!!")