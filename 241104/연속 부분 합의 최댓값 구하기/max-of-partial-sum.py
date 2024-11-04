import sys

n = int(input())

INT_MIN = -1 * sys.maxsize

arr = list(map(int, input().split()))

dp = [INT_MIN for _ in range(n)]

dp[0] = arr[0]

for i in range(1, n):
    dp[i] = max(dp[i-1]+arr[i], arr[i])

ans = 0
for a in dp:
    ans = max(ans, a)

print(ans)