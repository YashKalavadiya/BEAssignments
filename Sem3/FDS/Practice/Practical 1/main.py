
class StudentSportsClassifier:

    def __init__(self):
        self.cricket = []
        self.football = []
        self.badminton = []
        self.allStudents = []

    def removeDuplicate(self, li):
        tempList = []
        for i in li:
            if i not in tempList:
                tempList.append(int(i))
        return tempList

    def cricketAndMinton(self):
        for stud in self.cricket:
            if stud in self.badminton:
                print(stud, end=" ")
        print()

    def eitherCrickOrMinton(self):
        for stud in self.allStudents:
            if stud in self.cricket and stud not in self.badminton:
                print(stud, end=" ")
            elif stud in self.badminton and stud not in self.cricket:
                print(stud, end=" ")

    def neitherCrickNotMinton(self):
        for stud in self.allStudents:
            if stud not in self.cricket and stud not in self.badminton:
                print(stud, end=" ")
        print()

    def crickAndFootball(self):
        for stud in self.allStudents:
            if stud in self.cricket and stud in self.football and stud not in self.badminton:
                print(stud, end=" ")
        print()

    def getData(self):
        self.cricket = self.removeDuplicate(
            list(input("Enter roll no of students who play cricket(space seperated)").split(" ")))
        self.football = self.removeDuplicate(
            list(input("Enter roll no of students who play Football(space seperated)").split(" ")))
        self.badminton = self.removeDuplicate(
            list(input("Enter roll no of students who play Badminton(space seperated)").split(" ")))
        self.allStudents = self.removeDuplicate(list(self.cricket + self.football + self.badminton))

    def printMenu(self):
        print("MENU")
        print("1. Students who play both cricket and badminton")
        print("2. either cricket or badminton, but not both")
        print("3. students who play neither cricket nor badminton")
        print("4. students who play cricket and football but not badminton")
        print("5. EXIT")

    def execute(self):
        isExit = False
        self.getData()
        while not isExit:
            self.printMenu()
            ch = int(input("Enter your choice: "))
            if ch == 1:
                self.cricketAndMinton()
            elif ch == 2:
                self.eitherCrickOrMinton()
            elif ch == 3:
                self.neitherCrickNotMinton()
            elif ch == 4:
                self.crickAndFootball()
            elif ch == 5:
                isExit = True

s = StudentSportsClassifier()
s.execute()
