import heapq
import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

graph = [[] for _ in range(n+1)]
pq = []
ans = []

dist = [INT_MAX] * (n+1)
path = [0] * (n+1)


for _ in range(m):
    x, y, z = tuple(map(int, input().split()))
    
    graph[x].append((y, z))
    graph[y].append((x, z))

a, b = tuple(map(int, input().split()))

dist[a] = 0
heapq.heappush(pq, (0, a))

while pq:
    cur_dist, cur_idx = heapq.heappop(pq)

    if cur_dist != dist[cur_idx]:
        continue
    
    for tg_idx, tg_dist in graph[cur_idx]:
        new_dist = dist[cur_idx] + tg_dist

        if dist[tg_idx] > new_dist:
            dist[tg_idx] = new_dist
            heapq.heappush(pq, (new_dist, tg_idx))
            path[tg_idx] = cur_idx

print(dist[b])

x = b
rot = [b]
while x != a:
    x = path[x]
    rot.append(x)
print(*rot[::-1])