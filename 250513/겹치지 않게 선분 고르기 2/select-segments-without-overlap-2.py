n = int(input())

lines = [
    tuple(map(int, input().split()))
    for _ in range(n)
]

dp = [1]*n

lines.sort()

for i in range(1, n):
    for j in range(0, i):
        x1, _ = lines[i]
        _, x2 = lines[j]

        if x2 < x1:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))