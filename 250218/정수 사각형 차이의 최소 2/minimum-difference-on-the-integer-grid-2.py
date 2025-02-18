import sys

INT_MAX = sys.maxsize
MAX_R = 100

n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [[0] * n for _ in range(n)]

ans = INT_MAX

def init():
    for i in range(n):
        for j in range(n):
            dp[i][j] = INT_MAX
    
    dp[0][0] = grid[0][0]

    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0], grid[i][0])
        dp[0][i] = max(dp[0][i-1], grid[0][i])

def solve(low_b):
    for i in range(n):
        for j in range(n):
            if grid[i][j] < low_b:
                grid[i][j] = INT_MAX
    
    init()

    for i in range(1, n):
        for j in range(1, n):
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), grid[i][j])
    
    return dp[n-1][n-1]

for low_b in range(1, MAX_R+1):
    up_b = solve(low_b)

    if up_b == INT_MAX:
        continue
    
    ans = min(ans, up_b-low_b)

print(ans)