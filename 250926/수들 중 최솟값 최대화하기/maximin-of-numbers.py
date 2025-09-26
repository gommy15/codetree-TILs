n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False] * n

selc_spot = []
ans = 0

def find_min_max(r):
    global ans

    if r == n:
        ans = max(ans, min(selc_spot))
        return
    
    for i in range(n):
        if visited[i]:
            continue
        
        visited[i] = True
        selc_spot.append(grid[r][i])
        find_min_max(r+1)

        selc_spot.pop()
        visited[i] = False

find_min_max(0)

print(ans)