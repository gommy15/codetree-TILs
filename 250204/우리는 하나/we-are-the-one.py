from collections import deque

n, k, u, d = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

q = deque()
visited = [[0 for _ in range(n)] for _ in range(n)]
ans = 0

selc_city = []

dxs, dys = [-1, 0, 1, 0], [0, 1, 0, -1]

def can_go(x, y, num):
    return 0<=x<n and 0<=y<n and not visited[x][y] and u<=abs(num-grid[x][y])<=d

def bfs():
    while q:
        x, y = q.popleft()
        num = grid[x][y]

        for dx, dy in zip(dxs, dys):
            nx, ny = x+dx, y+dy

            if can_go(nx, ny, num):
                q.append((nx, ny))
                visited[nx][ny] = 1

def calc():
    for i in range(n):
        for j in range(n):
            visited[i][j] = 0
    
    for x, y in selc_city:
        q.append((x, y))
        visited[x][y] = 1
    
    bfs()

    return sum([
        visited[i][j]
        for i in range(n)
        for j in range(n)
    ])


def find_city(cnt):
    global ans

    if cnt == k:
        ans = max(ans, calc())
        return
    
    for i in range(n):
        for j in range(n):
            selc_city.append((i, j))
            find_city(cnt+1)
            selc_city.pop()


find_city(0)
print(ans)