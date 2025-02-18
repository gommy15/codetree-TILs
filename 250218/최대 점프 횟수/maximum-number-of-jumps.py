import sys

INT_MIN = -sys.maxsize

n = int(input())

arr = list(map(int, input().split()))
dp = [INT_MIN] * n

dp[0] = 0

for i in range(1, n):
    for j in range(i):
        if j+arr[j] >= i and dp[j] is not INT_MIN:
            dp[i] = max(dp[i], dp[j]+1)

ans = 0
for i in range(n):
    ans = max(ans, dp[i])

print(ans)