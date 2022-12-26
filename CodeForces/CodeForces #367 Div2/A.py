import math
    
a, b = [float(i) for i in input().split()]
n = int(input())
mini = 100000000.0
for i in range(n):
    x, y, v = [float(i) for i in input().split(' ')]
    mini = min(mini, math.sqrt(float((x - a) * (x - a) + (y - b) * (y - b))) / v)
print(mini)