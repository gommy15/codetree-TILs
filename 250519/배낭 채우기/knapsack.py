n, m = tuple(map(int, input().split()))

info = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0] * (m+1)

for w, v in info:
    for i in range(m, -1, -1):
        if i >= w:
            dp[i] = max(dp[i], dp[i-w]+v)

print(max(dp))