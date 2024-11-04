n = int(input())

arr = list(map(int, input().split()))

dp = [0 for _ in range(n)]

dp[0] = arr[0]

for i in range(1, n):
    dp[i] = max(dp[i-1]+arr[i], arr[i])

ans = 0
for a in dp:
    ans = max(ans, a)

print(ans)