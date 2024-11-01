from collections import deque

n = int(input())

sr, sc, er, ec = tuple(map(int, input().split()))

step = [[-1 for _ in range(n)] for _ in range(n)]
visited = [[0 for _ in range(n)] for _ in range(n)]
q = deque()

def canGo(x, y):
    return 0<=x<n and 0<=y<n and not visited[x][y]

def bfs():
    dxs, dys = [-2, -1, 1, 2, 2, 1, -1, -2], [1, 2, 2, 1, -1, -2, -2, -1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if canGo(nx, ny):
                visited[nx][ny] = True
                q.append((nx, ny))
                step[nx][ny] = step[x][y]+1

visited[sr-1][sc-1] = True
q.append((sr-1, sc-1))
step[sr-1][sc-1] = 0

bfs()

print(step[er-1][ec-1])