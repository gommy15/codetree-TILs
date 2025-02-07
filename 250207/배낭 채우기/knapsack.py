import sys

INT_MIN = -sys.maxsize

n, m = tuple(map(int, input().split()))

info = [(0, 0)] + [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [[INT_MIN] * (m+1) for _ in range(n+1)]

dp[0][0] = 0

for i in range(1, n+1):
    w, v = info[i]

    for j in range(m+1):
        if j >= w:
            dp[i][j] = max(dp[i-1][j-w]+v, dp[i-1][j])
        else:
            dp[i][j] = dp[i-1][j]

print(max(dp[n]))

