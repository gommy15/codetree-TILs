n, m = tuple(map(int, input().split()))
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

ans = 0

for i in range(n):
    cnt = 1
    max_cnt = 1

    for j in range(n-1):
        if grid[i][j] == grid[i][j+1]:
            cnt += 1
        else:
            max_cnt = max(max_cnt, cnt)
            cnt = 1
    
    max_cnt = max(max_cnt, cnt)
    if max_cnt >= m:
        ans += 1

    #print(ans)
    cnt = 1
    max_cnt = 1

    for j in range(n-1):
        if grid[j][i] == grid[j+1][i]:
            cnt += 1
        else:
            max_cnt = max(max_cnt, cnt)
            cnt = 1
    
    max_cnt = max(max_cnt, cnt)
    if max_cnt >= m:
        ans += 1

print(ans)