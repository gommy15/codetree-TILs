import sys

INT_MAX = sys.maxsize

n = int(input())
arr = [0] + list(map(int, input().split()))

m = sum(arr)

dp = [[0] * (m+1) for _ in range(n+1)]

dp[0][0] = True

for i in range(1, n+1):
    for j in range(m+1):
        # i 번째 수를 선택했을 경우
        if j >= arr[i] and dp[i-1][j-arr[i]]:
            dp[i][j] = True

        # i 번째 수를 선택하지 않았을 경우
        if dp[i-1][j]:
            dp[i][j] = True

ans = INT_MAX

for i in range(1, m):
    if dp[n][i]:
        ans = min(ans, abs(i-(m-i)))

print(ans)