n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False]*n
picked = []

ans = 0

def find_max(r):
    global ans

    if r == n:
        summ = 0
        for i in range(n):
            summ += grid[i][picked[i]]
        
        ans = max(ans, summ)
        return

    for i in range(n):
        if visited[i]:
            continue
        
        visited[i] = True
        picked.append(i)

        find_max(r+1)

        visited[i] = False
        picked.pop()

find_max(0)

print(ans)