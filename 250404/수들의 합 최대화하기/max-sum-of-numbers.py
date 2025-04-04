n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False]*n
picked = []

ans = 0

def find_max(row):
    global ans

    if row == n:
        sum_val = 0
        for i in range(n):
            sum_val += grid[i][picked[i]]
        
        ans = max(ans, sum_val)
        return
    
    for i in range(n):
        if visited[i]:
            continue
        
        visited[i] = True
        picked.append(i)

        find_max(row+1)

        visited[i] = False
        picked.pop()

find_max(0)

print(ans)