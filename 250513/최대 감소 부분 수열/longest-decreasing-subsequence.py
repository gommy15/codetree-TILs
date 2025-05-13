import sys

INT_MAX = sys.maxsize

n = int(input())

arr = [INT_MAX] + list(map(int, input().split()))
dp = [0]*(n+1)

for i in range(1, n+1):
    for j in range(0, i):
        if arr[j] > arr[i]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))

