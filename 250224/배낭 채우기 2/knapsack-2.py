n, m = tuple(map(int, input().split()))

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0] * (m+1)

for i in range(1, m+1):
    for w, v in info:
        if i >= w:
            dp[i] = max(dp[i], dp[i-w] + v)

print(dp[m])