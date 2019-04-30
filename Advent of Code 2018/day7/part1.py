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

# Find the starting point, the character exist in the first list(pre), but not in the second list(block)
for char in pre:
	if char not in block and char not in ready:
		ready.append(char)

tempReady = []
count = 0

# process the first step in the ready list every time
while len(ready) > 0:
	tempReady = []
	ready = sorted(ready)
	current = ready[0]
	finished.append(current)
	ready.pop(0)

	# check which step could become available and put in tempReady list
	for job in jobs:
		if current in job.keys():
			tempReady.append(job[current])

	# if the step require more than one step in the first list, do not include them
	for temp in tempReady:
		for job in jobs:
			if temp in job.values():
				count += 1
		if count == 1:
			ready.append(temp)
		count = 0

	# change the value so it won't count in the future rounds
	for job in jobs:
		if current in job.keys():
			job[current] = 1

print(finished)