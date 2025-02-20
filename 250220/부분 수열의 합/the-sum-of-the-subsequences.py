n, m = tuple(map(int, input().split()))

seq = list(map(int, input().split()))

dp = [False] * (m+1)

dp[0] = True

for num in seq:
    for i in range(m, -1, -1):
        if i >= num and dp[i-num]:
            dp[i] = True

print("Yes" if dp[m] else "No")