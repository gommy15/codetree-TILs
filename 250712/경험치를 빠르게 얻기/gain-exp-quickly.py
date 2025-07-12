import sys

INT_MIN = -sys.maxsize
INT_MAX = -INT_MIN

n, m = tuple(map(int, input().split()))

qest = [(0, 0)]+[
    tuple(map(int, input().split()))
    for _ in range(n)
]

t = sum(rt for _, rt in qest)

dp = [[INT_MIN]*(t+1) for _ in range(n+1)]

dp[0][0] = 0

for i in range(1, n+1):
    for j in range(t+1):
        if j - qest[i][1] >= 0:
            dp[i][j] = max(dp[i][j], dp[i-1][j-qest[i][1]]+qest[i][0])
        
        dp[i][j] = max(dp[i][j], dp[i-1][j])

ans = next((j for j in range(t + 1) if dp[n][j] >= m), -1)

print(ans)

