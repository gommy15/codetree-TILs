import sys

INT_MIN = -1*sys.maxsize

n, m = tuple(map(int, input().split()))

weight, value = [], []

for _ in range(n):
    w, v = tuple(map(int, input().split()))
    weight.append(w)
    value.append(v)

dp = [0] * (m+1)


dp[0] = 0

for i in range(1, m+1):
    for j in range(n):
        if i >= weight[j]:
            dp[i] = max(dp[i], dp[i-weight[j]]+value[j])

ans = 0

for i in range(m+1):
    ans = max(ans, dp[i])

print(ans)