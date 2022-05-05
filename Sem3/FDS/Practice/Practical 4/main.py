import random
def parseInputs(val):
    return int(val)

def generateFiboSeries(n):
    series = [0, 1, 1]
    first = 0
    second = 1
    nex = first + second
    while nex <= n:
        first = second
        second = nex
        nex = first + second
        series.append(nex)
    return series


class SearchingAlgo:
    def __init__(self):
        self.studentsRandom = list(
            map(parseInputs, input("Enter roll no of students who attended training program (space seperated): ").split(" ")))
        random.shuffle(self.studentsRandom)
        self.studentsSorted = sorted(self.studentsRandom)
        print("Randomized students: ", self.studentsRandom)
        print("Sorted students: ", self.studentsSorted)

    def linearSearch(self):
        key = int(input("Enter No you want to search: "))
        for ele, idx in enumerate(self.studentsRandom):
            if ele == key:
                print("Element found at Index: ", idx)
                return
        print("Element not found")
        return

    def sentinalSearch(self):
        key = int(input("Enter No you want to search: "))
        tempList = self.studentsRandom

    @staticmethod
    def binaryHelper(f, l, m, li, key):
        if f > l:
            return -1
        if li[m] < key:
            return SearchingAlgo.binaryHelper(m+1, l, (m+1 + l)//2, li, key)
        elif li[m] > key:
            return SearchingAlgo.binaryHelper(f, m-1, (f + m-1)//2, li, key)
        else:
            return m

    def binarySearch(self):
        key = int(input("Enter No you want to search: "))
        tempList = self.studentsSorted
        isPresent = SearchingAlgo.binaryHelper(0, len(tempList)-1, len(tempList)//2, tempList, key)
        if isPresent == -1:
            print("Element Not Found")
        else:
            print("Element found at index: ", isPresent)


    def fibonacciSearch(self):
        key = int(input("Enter No you want to search: "))
        tempList = self.studentsSorted
        series = generateFiboSeries(len(tempList))
        n = len(tempList) - 1
        m = len(series) - 1
        ofs = -1
        i = min((ofs + series[m - 2]), n)
        print(series)
        if n < (ofs + series[m - 2]):
            print("HELLOOOOOOOOOOOOOOOOOOOOO")
        while m > 0:
            if tempList[i] == key:
                print("Element Found at index: ", i)
                return
            elif tempList[i] < key:
                ofs = i
                m -= 1
            else:
                m -= 1
            i = min((ofs + series[m-2]), n)
        print("Element Not Found")

    def printMenu(self):
        print("MENU")
        print("1. Search using linear search")
        print("2. Search using sentinel Search")
        print("3. Search using binary search")
        print("4. Search using fibonacci search")
        print("5. EXIT")

    def execute(self):
        isExit = False

        while not isExit:
            self.printMenu()
            ch = int(input("Enter your choice: "))
            if ch == 1:
                self.linearSearch()
            elif ch == 2:
                self.sentinalSearch()
            elif ch == 3:
                self.binarySearch()
            elif ch == 4:
                self.fibonacciSearch()
            else:
                isExit = True


s = SearchingAlgo()
s.execute()
