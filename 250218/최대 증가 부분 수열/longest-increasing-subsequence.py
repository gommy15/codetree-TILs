n = int(input())

arr = [0] + list(map(int, input().split()))

dp = [0] * (n+1)

for i in range(1, n+1):
    for j in range(i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], dp[j]+1)

ans = 0

for i in range(1, n+1):
    ans = max(ans, dp[i])

print(ans)
