from collections import deque

n = int(input())
r1, c1, r2, c2 = tuple(map(int, input().split()))

visited = [[-1 for _ in range(n)] for _ in range(n)]

q = deque()

def can_go(x, y):
    return 0<=x<n and 0<=y<n and visited[x][y] == -1

def bfs():
    dxs, dys = [-2, -1, 1, 2, 2, 1, -1, -2], [-1, -2, -2, -1, 1, 2, 2, 1]

    while q:
        x, y = q.popleft()

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny):
                visited[nx][ny] = visited[x][y] + 1
                q.append((nx, ny))

visited[r1-1][c1-1] = 0
q.append((r1-1, c1-1))

bfs()

print(visited[r2-1][c2-1])