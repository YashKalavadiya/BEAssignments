percentage = []

repeatAgain = True

def partition(low,high):
	i = (low-1)
	pivot = percentage[high]

	for j in range(low,high):
		if percentage[j]<=pivot:
			i=i+1
			percentage[i],percentage[j]=percentage[j], percentage[i]

	percentage[i+1], percentage[high]=percentage[high],percentage[i+1]

	return (i+1)

def percentageOperation(low,high):
	#if len(percentage)==1:
	#	return percentage

	if low < high:
		pi = partition(low,high)
		percentageOperation(low,pi-1)
		percentageOperation(pi+1,high)

while repeatAgain:
  percentage.clear()
  noOfStudents = int(input("\nEnter total number of student: "))

  print("\nEnter the percentage of all students one by one \n\n")
  
  for i in range(noOfStudents):
 	  percentage.append(float(input("Enter percentage:"))) 
  
  print("\nEntered list :",percentage)

  n=noOfStudents-1
	
  percentageOperation(0,n)
  
  print("\nSorted list after Quick Sort: ",percentage)
  
  print("\nTOP 5 STUDENTS PERCENTAGE:\n")
	
  for i in range(n,n-5,-1):
	
  	print(percentage[i])
  
  yn=input("\nDo you want to perform again(y/n) ")

  if yn=="n":
    repeatAgain=False

print("\n\nThank You!!")