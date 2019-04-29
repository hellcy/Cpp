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
#print(pre)
#print(block)

for char in pre:
	if char not in block and char not in ready:
		ready.append(char)

tempReady = []
count = 0

while len(ready) > 0:
	tempReady = []
	ready = sorted(ready)
	current = ready[0]
	finished.append(current)
	print(current)
	print(ready)
	ready.pop(0)

	for job in jobs:
		if current in job.keys():
			tempReady.append(job[current])

	for temp in tempReady:
		for job in jobs:
			if temp in job.values():
				count += 1
		if count >= 2:
			tempReady.remove(temp)

	for temp in tempReady:
		ready.append(temp)
	print(tempReady)

	for job in jobs:
		for temp in tempReady:
			if temp in job.values():
				jobs.remove(job)


			#print(job[current])
			#ready.append(job[current])

print(finished)