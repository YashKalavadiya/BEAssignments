isEnd = False
matrix1 = []
matrix2 = []
row1 = 0
col1 = 0
row2 = 0
col2 = 0

def parseInputEle(val):
    return int(val)

def getZerosList(length):
    arr = []
    for i in range(0, length):
        arr.append(0)
    return arr

def appendZeroes(arr, count):
    for i in range(0, count):
        arr.append(0)
    return arr

def printMatrix(m):
    for row in m:
        for col in row:
            print("", col, end="")
        print()

def getFormatedMatrix(m1, m2):
    diff = len(m1) - len(m2)
    if diff > 0:
        for i in range(0, diff):
            m2.append(getZerosList(len(m1[-1])))
    elif diff < 0:
        for i in range(0, abs(diff)):
            m1.append(getZerosList(len(m2[-1])))
    if len(m1[0]) > len(m2[0]):
        diff = abs(len(m1[0]) - len(m2[0]))
        for i in range(0, len(m2)):
            m2[i] = appendZeroes(m2[i], diff)
    elif len(m1[0]) < len(m2[0]):
        diff = abs(len(m1) - len(m2))
        for i in range(0, len(m1)):
            m1[i] = appendZeroes(m2[i], diff)
    return m1, m2
def printMenu():
    print("MENU:")
    print("1. Add Two Matrix")
    print("2. substract two matrix")
    print("3. Multiply two matrix")
    print("4. Transpose of matrix")
    print("5. Exit")
    print("6. Re Enter Matrix")
def inputMatrix(row, col):
    matrix = []
    print("Enter ", row, " * ", col, " matrix(seperate elements of row by single space and new line for col):")
    for i in range(0, row):
        row = list(map(parseInputEle, input().split(" ")))
        matrix.append(row)
    for i in matrix:
        if len(i) != col:
            print("Invalid elements of ", row, " * ", col, " matrix.")
            return []
    print(matrix)
    return matrix

def checkCanMultiply(m1, m2):
    row1 = len(m1)
    row2 = len(m2)
    col1 = len(m1[0])
    col2 = len(m2[0])

    if col1 == row2:
        return m1,m2
    elif row1 == col2:
        return m2, m1
    return [], []
    

def addMatrix(m1, m2):
    # row = max(len(m1), len(m2))
    m1, m2 = getFormatedMatrix(m1, m2)
    addition = []
    for i in range(0, len(m1)):
        rowSum = []
        for j in range(0, len(m1[i])):
            sum = m1[i][j] + m2[i][j]
            rowSum.append(sum)
        addition.append(rowSum)
    printMatrix(addition)

def substratcMatrix(m1, m2):
    # row = max(len(m1), len(m2))
    m1, m2 = getFormatedMatrix(m1, m2)
    addition = []
    for i in range(0, len(m1)):
        rowSub = []
        for j in range(0, len(m1[i])):
            sub = m1[i][j] - m2[i][j]
            rowSub.append(sub)
        addition.append(rowSub)
    printMatrix(addition)

def multiplyMatrix(m1, m2):
    m1, m2 = checkCanMultiply(m1,m2)

    if bool(m1) and bool(m2):
        multiplied = []
        for i in range(0, len(m1)):
            row = []
            for j in range(0, len(m2[0])):
                mul = 0
                for k in range(0, len(m2)):
                    mul += m1[i][k] * m2[k][j]
                row.append(mul)
            multiplied.append(row)
        printMatrix(multiplied)

def getTranspose(m1, m2):
    transpose1 = []
    transpose2 = []
    for i in range(0, len(m1[0])):
        row = []
        for j in range(0, len(m1)):
            row.append(m1[j][i])
        transpose1.append(row)
    for i in range(0, len(m2[0])):
        row = []
        for j in range(0, len(m2)):
            row.append(m2[j][i])
        transpose2.append(row)
    print("Transpose of maatrix 1: ---------")
    printMatrix(transpose1)
    print("Transpose of maatrix 2: ---------")
    printMatrix(transpose2)

while not isEnd:
    while not bool(matrix1):
        print("For Matrix 1: ")
        row1 = int(input("Enter No of rows: "))
        col1 = int(input("Enter number of cols: "))
        matrix1 = inputMatrix(row1, col1)
    while not bool(matrix2):
        print("For Matrix 2: ")
        row2 = int(input("Enter no of rows: "))
        col2 = int(input("Enter number of cols: "))
        matrix2 = inputMatrix(row2, col2)
    printMenu()
    choice = int(input("Enter Choice: "))
    if choice == 1:
        print("Addition")
        addMatrix(matrix1, matrix2)
    elif choice == 2:
        substratcMatrix(matrix1, matrix2)
    elif choice == 3:
        multiplyMatrix(matrix1, matrix2)
    elif choice == 4:
        getTranspose(matrix1, matrix2)
    elif choice == 5:
        isEnd = True
    elif choice == 6:
        matrix1 = []
        matrix2 = []
    else:
        print("Invalid")

