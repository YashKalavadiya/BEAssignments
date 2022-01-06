import math

sentence = ""
isEnd = False
def printMenu():
    print("1. Display word with longest length")
    print("2. frequency of letter in a sentence")
    print("3. check if string is palindrome")
    print("4. index of first apperance of substring")
    print("5. count occurrance of given word in string")
    print("6. Change String")
    print("7. Exit")

def getWordWithLongestLength(sentence):
    arr = sentence.split(" ")
    maxLen = 0
    maxWord = ""
    for word in arr:
        if maxLen < len(word):
            maxWord = word
            maxLen = len(word)
    return maxWord

def getFrequency(sentence, character):
    occurrence = 0
    for c in sentence:
        if c == character:
            occurrence += 1
    return occurrence

def checkPalindrome(sentence):
    length = len(sentence)
    mid = math.floor(length/2)
    if mid == float(length/2):
        start = 0
        end = len(sentence) - 1
        while start < mid and end > mid:
            if sentence[start] != sentence[end]:
                return False
            start += 1
            end -= 1
        return True
    else:
        start = 0
        end = len(sentence) - 1
        while start <= mid and end > mid:
            if sentence[start] != sentence[end]:
                return False
            start += 1
            end -= 1
        return True

def indexOfFirstApperance(sentence, substring):
    arr = sentence.split(" ")
    for ele in arr:
        if ele == substring:
            return arr.index(ele)
    return -1
    # return sentence.find(substring)

def countOccurance(sentence, word):
    arr = sentence.split(" ")
    count = 0
    for ele in arr:
        if word == ele:
            count += 1
    return count


sentence = input("Enter String: ")
while(not isEnd):
    printMenu()
    choice = int(input("Enter Choice: "))
    if choice == 1:
        print("Word with max length is: ", getWordWithLongestLength(sentence))
    elif choice == 2:
        char = input("Enter Character to get its frequency: ")[0]
        print("Frequency: ", getFrequency(sentence, char))
    elif choice == 3:
        if checkPalindrome(sentence):
            print("Entered string is palindrome")
        else:
            print("Entered string is not palindrome!!! (Try changing it)")
    elif choice == 4:
        char = input("Enter substring to search: ")
        print("Index of given substring: ", indexOfFirstApperance(sentence, char))
    elif choice == 5:
        char = input("Enter substring to get it occurance: ")
        print("occurance of given substring: ", countOccurance(sentence, char))
    elif choice == 6:
        sentence = input("Enter New Sentence: ")
    elif choice == 7:
        isEnd = True
    else:
        print("Invalid Option!!!!!")

    