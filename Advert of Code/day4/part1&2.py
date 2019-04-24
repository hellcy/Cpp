import re
from collections import defaultdict

def run(s):
    # :param s: input in string format
    # :return: solution flag
    # Your code goes here
    logs = sorted(s.split("\n")) # sort inputs
    #print(logs)
    current_id = None
    max_id = None
    temp = 0
    max_minute = 0
    time_falls_asleep = dict() # {}
    total_sleep_time = defaultdict(int)
    minutes_asleep = dict()
    for log in logs:
        if "begins shift" in log:
            current_id = int(re.findall(r'-?\d+', log[18:])[0])
            if current_id not in minutes_asleep:
                minutes_asleep[current_id] = defaultdict(int)
        elif "falls asleep" in log:
            h = int(log[12:14])
            m = int(log[15:17])
            time_falls_asleep[current_id] = (h,m)
        elif "wakes up" in log:
            h1 = int(log[12:14])
            m1 = int(log[15:17])
            h0, m0 = time_falls_asleep[current_id]
            delta_min = h1*60 + m1 - (h0*60 + m0)

            total_sleep_time[current_id] += delta_min
            for i in range(delta_min):
                minutes_asleep[current_id][m0 + i] += 1
                temp = minutes_asleep[current_id][m0 + i]
                if temp > max_minute:
                    max_minute = temp
                    max_id = current_id

    c_max, _ = max(total_sleep_time.items(), key=lambda x:x[1])
    m_max,_ = max(minutes_asleep[c_max].items(), key=lambda x:x[1] )
    print(c_max * m_max)
    # return c_max * m_max
    print(max_id)
    print(max_minute)
    print(minutes_asleep[max_id])
    print(30 * max_id)

with open("input.txt") as file:
    data=file.read()
    run(data)