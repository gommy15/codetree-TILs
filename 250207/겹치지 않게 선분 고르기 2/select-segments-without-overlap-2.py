n = int(input())

seg = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [0] * n

seg.sort()

for i in range(n):
    dp[i] = 1

    for j in range(i):
        x1, _ = seg[i]
        _, x2 = seg[j]

        if x2 < x1:
            dp[i] = max(dp[i], dp[j]+1)

ans = 0

"""for i in range(n):
    ans = max(ans, dp[i])"""

print(max(dp))