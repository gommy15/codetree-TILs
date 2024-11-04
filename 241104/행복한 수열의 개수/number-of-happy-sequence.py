n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

arr = [0 for _ in range(n)]

ans = 0

def checkArr():
    max_cnt = 1
    cnt = 1
    for i in range(1, n):
        if arr[i] == arr[i-1]:
            cnt += 1
        else:
            cnt = 1

        max_cnt = max(max_cnt, cnt)
    
    return max_cnt >= m

for i in range(n):
    arr = grid[i][:]
    if checkArr():
        ans += 1
    
    for j in range(n):
        arr[j] = grid[j][i]
    
    if checkArr():
        ans += 1

print(ans)