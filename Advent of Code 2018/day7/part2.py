with open("input.txt") as file:
	pre = []
	block = []
	ready = []
	jobs = []
	finished = []
	for line in file.readlines():
		letter1 = line.split(" ")[1]
		letter2 = line.split(" ")[7]
		jobs.append(
			{
				letter1 : letter2
			}
			
		)

		pre.append(
    		letter1
		)

		block.append(
    		letter2
		)

processing = {}
tempReady = []
count = 0
second = 0

def calTime(char):
	return ord(char) - 4

def checkReady(char):
	count = 0
	tempReady = []
	# check which step could become available and put in tempReady list
	for job in jobs:
		if char in job.keys():
			tempReady.append(job[char])

	# if the step require more than one step in the first list, do not include them
	for temp in tempReady:
		for job in jobs:
			if temp in job.values():
				count += 1
		if count == 1:
			ready.append(temp)
		count = 0
	read = sorted(ready)

	# change the value so it won't count in the future rounds
	for job in jobs:
		if char in job.keys():
			job[char] = 1

# Find the starting point, the character exist in the first list(pre), but not in the second list(block)
for char in pre:
	if char not in block and char not in ready:
		ready.append(char)

for item in ready:
	processing[item] = calTime(item)

ready = []
while len(processing) > 0:
	second += 1
	for key in processing.keys():
		processing[key] += -1
		if processing[key] == 0:
			checkReady(key)
			print(ready)

	for key in [key for key in processing if processing[key] <= 0]: del processing[key]

	remove = []

	for item in ready:	
		if len(processing) < 5:
			processing[item] = calTime(item)
			remove.append(item)

	for item in remove:
		ready.remove(item)

print(second)



