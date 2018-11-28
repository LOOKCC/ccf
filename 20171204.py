x = input()
points = int(x.split(' ')[0])
edges = int(x.split(' ')[1])
maps = [[] for i in range(points+1)]
for i in range(edges):
    x = input()
    x = [int(y) for y in x.split(' ')]
    maps[x[1]].append([x[0], x[2], x[3]])
    maps[x[2]].append([x[0], x[1], x[3]])

dis = [100000000000000 for i in range(points+1)]
dis[1] = 0
visited = [0 for i in range(points+1)]
small_road = [0 for i in range(points+1)]

while(True):
    u = -1
    for v in range(1, points+1):
        if visited[v] == 0:
            if u == -1 or dis[v] < dis[u]:
                u = v
    if u == -1:
        break 
    visited[u] = 1
    for i in range(len(maps[u])):
        if maps[u][i][0] == 0:
            if dis[maps[u][i][1]] > dis[u] + maps[u][i][2]:
                dis[maps[u][i][1]] = dis[u] + maps[u][i][2]
                small_road[maps[u][i][1]] = 0
        else:
            if small_road[u] == 0:
                temp = maps[u][i][2]
                if dis[maps[u][i][1]] > dis[u] + temp*temp:
                    dis[maps[u][i][1]] = dis[u] + temp*temp
                    small_road[maps[u][i][1]] = maps[u][i][2]
            else:
                temp = small_road[u] + maps[u][i][2]
                if dis[maps[u][i][1]] > dis[u] + temp*temp - small_road[u]*small_road[u]:
                    dis[maps[u][i][1]] = dis[u] + temp*temp - small_road[u]*small_road[u]
                    small_road[maps[u][i][1]] = small_road[u] + maps[u][i][2]
print(dis[points])