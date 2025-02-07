import heapq
import sys

INT_MAX = sys.maxsize

n, m = tuple(map(int, input().split()))

graph = [[] for _ in range(n+1)]

dist = [INT_MAX] * (n+1)
pq = []

for _ in range(m):
    i, j, d = tuple(map(int, input().split()))
    graph[j].append((i, d))
    
dist[n] = 0
heapq.heappush(pq, (0, n))

while pq:
    cur_dist, cur_idx = heapq.heappop(pq)

    if cur_dist != dist[cur_idx]:
        continue
    
    for tg_idx, tg_dist in graph[cur_idx]:
        new_dist = dist[cur_idx] + tg_dist

        if new_dist < dist[tg_idx]:
            heapq.heappush(pq, (new_dist, tg_idx))
            dist[tg_idx] = new_dist

print(max(dist[1:]))   