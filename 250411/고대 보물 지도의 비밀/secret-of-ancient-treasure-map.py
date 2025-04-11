import sys
INT_MIN = -sys.maxsize

n, k = tuple(map(int, input().split()))

arr = [0] + list(map(int, input().split()))

dp = [[INT_MIN]*(k+1) for _ in range(n+1)]

dp[0][0] = 0
ans = INT_MIN

for i in range(1, n+1):
    for j in range(k+1):
        if arr[i] < 0:
            if j and dp[i-1][j-1] != INT_MIN:
                dp[i][j] = max(arr[i], dp[i-1][j-1]+arr[i])
        else:
            dp[i][j] = max(arr[i], dp[i-1][j]+arr[i])
        
        ans = max(ans, dp[i][j])

print(ans)

