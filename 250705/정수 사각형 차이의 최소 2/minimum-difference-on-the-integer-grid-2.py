import sys

INT_MAX = sys.maxsize
MAX_R = 100

n = int(input())
nums = [
    list(map(int, input().split()))
    for _ in range(n)
]

dp = [
    [0]*n
    for _ in range(n)
]

ans = INT_MAX




def init():
    for i in range(n):
        for j in range(n):
            dp[i][j] = INT_MAX
    
    dp[0][0] = nums[0][0]

    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0], nums[i][0])
        dp[0][i] = max(dp[0][i-1], nums[0][i])

def solve(lb):
    for i in range(n):
        for j in range(n):
            if nums[i][j] < lb:
                nums[i][j] = INT_MAX

    init()

    for i in range(1, n):
        for j in range(1, n):
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), nums[i][j])
    
    return dp[n-1][n-1]

for lb in range(1, MAX_R+1):
    ub = solve(lb)

    if ub == INT_MAX:
        continue
    
    ans = min(ans, ub-lb)

print(ans)