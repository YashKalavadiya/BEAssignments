percentage = []
insertSort = []
shellSort = []

repeatAgain = True

def displayMainMenu():
  print("\n\nMAIN MENU")
  print("1. INSERTION SORT")
  print("2. SHELL SORT")

def sortOperations(choice):
    if(choice == 1):
        insertSort.extend(percentage)
        for i in range(1,len(insertSort)):
            key = insertSort[i]

            j = i-1
            while j >=0 and key < insertSort[j]:
                insertSort[j+1] = insertSort[j]
                j -= 1
            insertSort[j+1] = key
        print("\nSorted list after Insertion sort : ", insertSort)
                       

    elif (choice == 2):

        shellSort.extend(percentage)
        
        n = len(shellSort)
        gap= int(n/2)
        while gap > 0:
            for i in range(gap, n):
                temp = shellSort[i]

                j=i
                while j>=gap and shellSort[j-gap] > temp:
                    shellSort[j] = shellSort[j-gap]
                    j-=gap
                shellSort[j] = temp
            gap = int(gap/2)
        print("\nSorted list after Shell sort : ", shellSort)

        
    else:
        errorChoice = int(input("\nWrong choice code!!! please enter in 1 - 5 :"))
        sortOperations(errorChoice)

noOfStudents = int(input("Enter total number of students : "))

print("\nEnter the percentage of all students one by one \n\n")

for i in range(noOfStudents):
    percentage.append(float(input("Enter Percentage : ")))

print("\nEntered list : ",percentage)

while(repeatAgain):
  displayMainMenu()
  choice = int(input("\nEnter your choice code : "))
  sortOperations(choice)
  yn = input("\nDo you want to perform again (y/n) : ")
  if(yn == "n"):
    repeatAgain = False
print("\n\nThank you!!")