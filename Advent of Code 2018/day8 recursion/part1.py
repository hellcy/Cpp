mainList = []

with open("test.txt") as input_file:
    mainList = [line.strip().split() for line in input_file]
    mainList = list(map(int, mainList[0]))
answer = 0

# calculate the value from current list
def listValue(node):
	answer = 0
	for x in range(int(node[1])):
		answer += int(node[len(node) - int(node[1]) + x])
	return answer

# trim the given list 
def trimList(node):
	return node[2:]

def nodeLenth(node):
	if node[0] == "0":
		return 2 + int(node[1])
	#if node[0] == "1":


# main recursion function
def cal(mainList, nodeNum = 1):
	answer = 0
	pos = 0
	for child in range(nodeNum):
		header = mainList[pos:pos + 2]
		childNodeNum = header[0]
		metaEntriesNum = header[1]
		if childNodeNum == 0:
			pos += 2 + metaEntriesNum
			answer += sum(mainList[pos - metaEntriesNum:pos])
		else:
			newPos = cal(mainList[pos + 2:],childNodeNum)
			pos += newPos + metaEntriesNum
			answer += sum(mainList[pos - metaEntriesNum:pos])
	return pos + 2


pos = cal(mainList)

print(answer)

print(mainList)

#print(listValue(mainList))

print(trimList(mainList))

#print(cal(mainList))

#print(nodeLenth(mainList))
