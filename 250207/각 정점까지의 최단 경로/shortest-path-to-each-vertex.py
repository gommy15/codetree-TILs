import heapq
import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))
k = int(input())

graph = [[] for _ in range(n+1)]
pq = []

dist = [INT_MAX] * (n+1)

for _ in range(m):
    x, y, z = tuple(map(int, input().split()))

    graph[x].append((y, z))
    graph[y].append((x, z))

dist[k] = 0

heapq.heappush(pq, (0, k))

while pq:

    min_dist, min_idx = heapq.heappop(pq)

    if min_dist != dist[min_idx]:
        continue
    
    for target_idx, target_dist in graph[min_idx]:
        
        new_dist = dist[min_idx] + target_dist

        if dist[target_idx] > new_dist:
            dist[target_idx] = new_dist
            heapq.heappush(pq, (new_dist, target_idx))

for i in range(1, n+1):
    if dist[i] == INT_MAX:
        print(-1)
    else:
        print(dist[i])
