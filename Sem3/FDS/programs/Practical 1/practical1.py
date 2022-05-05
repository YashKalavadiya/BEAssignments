

def parseInputs(val):
    return int(val)


def removeDuplicate(arr):
    finalList = []
    for ele in arr:
        if ele not in finalList:
            finalList.append(ele)
    return finalList
badminton = []
cricket = []
football = []

badminton = input("Enter students for badminton(comma seperated): ").split(",")

cricket = input("Enter students for cricket(comma seperated): ").split(",")

football = input("Enter students for football(comma seperated): ").split(",")
cricket = list(map(parseInputs, cricket))
badminton = list(map(parseInputs, badminton))
football = list(map(parseInputs, football))
cricket = removeDuplicate(cricket)
football = removeDuplicate(football)
badminton = removeDuplicate(badminton)
cricketAndBadminton = []
eitherCirkOrMinton = []
crickNFootButNoMinton = []
onlyFootball = []
allstuds = removeDuplicate(list(cricket + football + badminton))

print("All: ", allstuds)
# Getting students who play cricket as well as badminton 

for ele in cricket:
    if ele in badminton:
        cricketAndBadminton.append(ele)

print("Students who play both cricket and badminton: ", cricketAndBadminton)
for ele in allstuds:
    if ele in badminton and ele not in cricket:
        eitherCirkOrMinton.append(ele)
    if ele in cricket and ele not in badminton:
        eitherCirkOrMinton.append(ele)
print("Students who play either cricket or badminton: ", eitherCirkOrMinton)

for ele in football:
    if ele not in cricket and ele not in badminton:
        onlyFootball.append(ele)

print("Students who play only football and not any other game: ", onlyFootball)

for ele in allstuds:
    if (ele in cricket and ele in football) and ele not in badminton:
        crickNFootButNoMinton.append(ele)

print("Cricket and football but no badminton: ", crickNFootButNoMinton)