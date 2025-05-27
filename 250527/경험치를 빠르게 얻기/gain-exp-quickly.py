import sys

INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize


n, m = tuple(map(int, input().split()))

qest = [(0, 0)] + [
    tuple(map(int, input().split()))
    for _ in range(n)
]

t = sum(time for _ , time in qest)

dp = [[INT_MIN]*(t+1) for _ in range(n+1)]

dp[0][0] = 0

for i in range(1, n+1):
    exp, runtime = qest[i]

    for j in range(t+1):
        if j >= runtime:
            dp[i][j] = max(dp[i][j], dp[i-1][j-runtime]+exp)
        
        dp[i][j] = max(dp[i][j], dp[i-1][j])

ans = INT_MAX

for j in range(t+1):
    if dp[n][j] >= m:
        ans = min(ans, j)

if ans == INT_MAX:
    ans = -1

print(ans)