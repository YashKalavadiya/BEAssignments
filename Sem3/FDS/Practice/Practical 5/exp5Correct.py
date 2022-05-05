def insertionSort(inputList):
    for i in range(1,len(inputList)):
        for j in range(i-1,-1,-1):
            if inputList[i] < inputList[j]:
                temp = inputList[j]
                inputList[j] = inputList[i]
                inputList[i] = temp
                i = j
        # print(inputList)
    return inputList
        
def shellSort(inputList):
    offset = len(inputList)
    while(offset >= 1):
        offset = offset // 2
        for i in range(0,len(inputList) - offset):
            if inputList[i] > inputList[i+offset]:
                inputList[i],inputList[i+offset] = inputList[i+offset],inputList[i]
                while(i-offset >= 0 and inputList[i-offset] > inputList[i]):
                    inputList[i],inputList[i-offset] = inputList[i-offset],inputList[i]
                    i = i - offset
        # print(inputList)
    return inputList





numberOfStudents = int(input("Enter the number of students who is in second year : "))
percentageList = []
for i in range(0,numberOfStudents):
    percentage = float(input(f"Enter the percentage of student {i+1}: "))
    percentageList.append(percentage)

print("Press 1 to sort using insertion sort")
print("Press 2 to sort using shell sort")
choice = int(input("Enter your choice : "))

match choice:
    case 1:
        percentageList = insertionSort(percentageList)
    case 2:
        percentageList = shellSort(percentageList)

print(percentageList[-1:-6:-1])