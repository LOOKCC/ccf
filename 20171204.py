x = input()
x = [int(y) for y in x.split(' ')]
point = x[0]
edge = x[1]
maps = [[] for i in range(point+1)]
for i in range(edge):
    x = input()
    x = [int(y) for y in x.split(' ')]
    maps[x[1]].append([x[0], x[2], x[3]])
print(maps)
