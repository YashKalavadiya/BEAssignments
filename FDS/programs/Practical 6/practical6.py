def parsePer(per):
    return float(per)

percentage = []


def partition(low,high):
	i = (low-1)
	pivot = percentage[high]

	for j in range(low,high):
		if percentage[j]<=pivot:
			i=i+1
			percentage[i],percentage[j]=percentage[j], percentage[i]

	percentage[i+1], percentage[high]=percentage[high],percentage[i+1]

	return (i+1)
def quickSort(l, r):
    if l <= r:
        pi = partition(l,r)
        print(percentage, l, r, pi)
        quickSort(l, pi-1)
        quickSort(pi+1, r)

def main():
    global percentage
    percentage = list(map(parsePer, input("Enter Percentage (seperated by space): ").split(" ")))
    quickSort(0, len(percentage)-1)
    print(percentage)


main()

# def quickSort(l, r, pivot):
#     if l == r or l < 0 or r < 0 or pivot == l == r or l > r:
#         return
#     while l < r:
#         print("Started")
#         if pivot < r and pivot == l:
#             if percentage[pivot] > percentage[r]:
#                 percentage[pivot], percentage[r] = percentage[r], percentage[pivot]
#                 pivot = r
#                 print("swaped with r")
#             else:
#                 r -= 1
#         elif pivot > l and pivot == r:
#             if percentage[pivot] < percentage[l]:
#                 percentage[pivot], percentage[l] = percentage[l], percentage[pivot]
#                 pivot = l
#                 print("swaped with l")
#             else:
#                 l += 1
#         else:
#             break
#         print(percentage)
#         print(l, r, pivot)
#     if l <= r:
#         quickSort(0, l-1, 0)
#         quickSort(r+1, len(percentage)-1, r+1)