n, m = tuple(map(int, input().split()))

info = [(0, 0)] + [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0] * (m+1)

for i in range(m+1):
    for j in range(1, n+1):
        w, v = info[j]

        if i >= w:
            dp[i] = max(dp[i], dp[i-w]+v)

print(max(dp))