n, m = tuple(map(int, input().split()))

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

seq = [0] * n
ans = 0

def isHappy():
    cnt = 1
    max_cnt = 1

    for i in range(1, n):
        if seq[i-1] == seq[i]:
            cnt += 1
        else:
            cnt = 1
        
        max_cnt = max(cnt, max_cnt)
    
    if max_cnt >= m:
        return True
    else:
        return False

for i in range(n):
    for j in range(n):
        seq[j] = grid[i][j]
    
    if isHappy():
        ans += 1


for i in range(n):
    for j in range(n):
        seq[j] = grid[j][i]
    
    if isHappy():
        ans += 1

print(ans)