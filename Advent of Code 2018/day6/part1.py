import re

def points():
    return [
        (x, y)
        for x in range(0,359)
        for y in range(0,359)
    ]

with open("input.txt") as file:
    overlap = 0
    coordinates = []
    for line in file.readlines():
    	coordinates.append(
    		{
    			"x": int(line.rstrip().split(',')[0]),
    			"y": int(line.rstrip().split(',')[1].strip()),
    		}
		)

    print(coordinates)

    overlaps = {}

	for point in points():
		print(point)

    # for claim in parsed_claims:
    #     for increment in increments(claim):
    #         if increment in overlaps:
    #             overlaps[increment] += 1
    #         else:
    #             overlaps[increment] = 1
    # overlapped_area = 0
    # for overlap in overlaps.values():
    #     if overlap > 1:
    #         overlapped_area += 1
    # print(overlapped_area)

    # for claim in parsed_claims:
    #     if all(overlaps[increment] == 1 for increment in increments(claim)):
    #         print(claim)

    # print(parsed_claims)
