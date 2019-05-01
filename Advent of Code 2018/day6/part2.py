import re

def points():
    return [
        (x, y)
        for x in range(46,348)
        for y in range(43,360)
    ]

def calDistance(point, coordinate):
	return abs(point[0] - coordinate[0]) + abs(point[1] - coordinate[1])

with open("input.txt") as file:
    coordinates = []
    for line in file.readlines():
    	coordinates.append(
    		(
    			int(line.rstrip().split(',')[0]),
    			int(line.rstrip().split(',')[1].strip()),
    		)
		)
#print(points())
print(coordinates)
minimum = 1000000
temp = 0
distance = 0
regionCount = 0
closestPointCount = {}

for point in points():
	for coordinate in coordinates:
		temp = calDistance(point, coordinate)
		tempPoint = coordinate
		if temp < minimum:
			minimum = temp
			minimumPoint = tempPoint
		elif temp == minimum:
			minimumPoint = (-1,-1)
		distance += temp
	#print(minimum)
	#print(point)
	#print(minimumPoint)
	if minimumPoint in closestPointCount:
		closestPointCount[minimumPoint] += 1
	else:
		closestPointCount[minimumPoint] = 1
	minimum = 1000000

	if distance < 10000:
		regionCount += 1

	distance = 0

print(closestPointCount)

maximum = max(closestPointCount, key=closestPointCount.get)
print(maximum, closestPointCount[maximum])
print(regionCount)
