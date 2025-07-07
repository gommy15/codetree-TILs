n, m = tuple(map(int, input().split()))

arr = list(map(int, input().split()))

dp = [-1] * (m+1)

dp[0] = 0

for num in arr:
    for i in range(m, -1, -1):
        if i >= num and dp[i-num] != -1:
            dp[i] = max(dp[i], dp[i-num]+1)

print("No" if dp[m] == -1 else "Yes")