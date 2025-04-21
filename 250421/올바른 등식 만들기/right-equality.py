MIN_M = 0
MAX_M = 40

OFFSET = 20

n, m = tuple(map(int, input().split()))

arr = [0]+list(map(int, input().split()))

dp = [[0] * (MAX_M+1) for _ in range(n+1)]

dp[0][OFFSET] = 1

m += OFFSET

for i in range(1, n+1):
    for j in range(MIN_M, MAX_M+1):
        # 1. i번째 숫자를 뺀 경우
        if j+arr[i] <= MAX_M:
            dp[i][j] += dp[i-1][j+arr[i]]
        
        # 2. i번째 숫자를 더한 경우
        if j-arr[i] >= MIN_M:
            dp[i][j] += dp[i-1][j-arr[i]]

print(dp[n][m])