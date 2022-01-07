

class StringOperations:
    def __init__(self):
        self.sentence = input("Enter sentence: ")

    def getLongest(self):
        words = self.sentence.split(" ")
        longest = ""
        for word in words:
            if len(word) > len(longest):
                longest = word
        print("Longest word is: ", longest)

    def getFrequency(self, char):
        count = 0
        for c in self.sentence:
            if c == char:
                count += 1
        print("Occurrence of ", c, " : ", count)

    def checkPalindrome(self, str):
        f = 0
        l = len(str)-1
        while f <= l:
            if str[f] == str[l]:
                f += 1
                l -= 1
            else:
                print("Not palindrome")
                return
        if f >= l:
            print("Palindrome.......")

    def checkSubstr(self, s):
        for idx in range(len(self.sentence) - len(s)):

            if self.sentence[idx:len(s)+idx] == s:
                print("found ", s, " at index: ", idx)
                return
        print("Substring not found")
        return

    def getWordsCount(self):
        words = {}
        allWords = list(self.sentence.split(" "))

        for word in allWords:
            if word in words.keys():
                words[word] += 1
            else:
                words[word] = 1
        print(words)
    def printMenu(self):
        print("MENU")
        print("1. Word with longest length")
        print("2. frequency of character")
        print("3. check palindrome")
        print("4. index of first appearance of substring")
        print("5. occurrence of word")
        print("6. change sentence")
        print("7. EXIT")

    def execute(self):
        isExit = False
        while not isExit:
            self.printMenu()
            ch = int(input("Enter your choice: "))
            if ch == 1:
                self.getLongest()
            elif ch == 2:
                char = input("Enter character to check its frequency: ")
                self.getFrequency(char)
            elif ch == 3:
                s = input("Enter str to check for palindrome: ")
                self.checkPalindrome(s)
            elif ch == 4:
                s = input("Enter substring to check in sentence: ")
                self.checkSubstr(s)
            elif ch == 5:
                self.getWordsCount()
            elif ch == 6:
                self.sentence = input("Enter new sentence: ")
            else:
                isExit = True

s = StringOperations()
s.execute()