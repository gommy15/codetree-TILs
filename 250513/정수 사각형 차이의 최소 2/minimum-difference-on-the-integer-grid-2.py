import sys

INT_MAX = sys.maxsize
MAX_R = 100

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [
    [
        [INT_MAX] * (MAX_R+1)
        for _ in range(n)
    ]
    for _ in range(n)
]

def init():
    for i in range(n):
        for j in range(n):
            for k in range(1, MAX_R+1):
                dp[i][j][k] = INT_MAX
    
    dp[0][0][grid[0][0]] = grid[0][0]

    for i in range(1, n):
        for k in range(1, MAX_R+1):
            dp[i][0][min(k, grid[i][0])] = min(dp[i][0][min(k, grid[i][0])], max(dp[i-1][0][k], grid[i][0]))
            dp[0][i][min(k, grid[0][i])] = min(dp[0][i][min(k, grid[0][i])], max(dp[0][i-1][k], grid[0][i]))


def solution():
    init()

    for i in range(1, n):
        for j in range(1, n):
            for k in range(1, MAX_R+1):
                dp[i][j][min(k, grid[i][j])] = min(dp[i][j][min(k, grid[i][j])], max(min(dp[i-1][j][k], dp[i][j-1][k]), grid[i][j]))


solution()

ans = INT_MAX
for k in range(1, MAX_R+1):
    if dp[n-1][n-1][k] != INT_MAX:
        ans = min(ans, dp[n-1][n-1][k]-k)

print(ans)