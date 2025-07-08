n, m = tuple(map(int, input().split()))

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0]*(m+1)

for i in range(1, m+1):
    for j in range(n):
        if i >= info[j][0]:
            dp[i] = max(dp[i], dp[i-info[j][0]] + info[j][1])

print(max(dp))