with open('input.txt') as f:
   ls = [s.strip() for s in f.readlines()]

init_state = "##...#......##......#.####.##.#..#..####.#.######.##..#.####...##....#.#.####.####.#..#.######.##..."

rules = {}

for l in ls:
   if len(l) > 1:
      r = l.split()   
      rules[r[0]] = r[2]

def sum_plants(curr):
   diff = (len(curr) - 100) // 2 # handle the negative serial number. Initial length is 100
   sum = 0
   for i, c in enumerate(curr): # mark pots in numbers start from 0
      if c == '#':
         sum += (i - diff)
   return sum

curr = init_state
print(len(init_state))
prev_sum = sum_plants(init_state)
diffs = []
num_iters = 1000
for i in range(num_iters):
   if(i == 20):
      print("Part 1: " + str(sum_plants(curr)))
   curr = "...." + curr + "...."
   next = "" # used to store plants information for next round
   for x in range(2, len(curr) - 2):
      sub = curr[x-2:x+3]
      next+= rules[sub]
   curr = next
   currsum = sum_plants(curr)
   diff = currsum - prev_sum
   diffs.append(diff)
   if(len(diffs) > 100): diffs.pop(0)
   prev_sum = currsum
print(diffs) # after certain iterations, the pots stablized and will only increase the same number for each round. We use this number multiply by the number of iterations.

last100diff = sum(diffs) // len(diffs)

total = (50000000000 - num_iters) * last100diff + sum_plants(curr) 

print("Part 2: " + str(total))