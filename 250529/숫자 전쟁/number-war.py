n = int(input())

fp = [0]+list(map(int, input().split()))
sp = [0]+list(map(int, input().split()))

dp = [[0] * (n+1) for _ in range(n+1)]

dp[0][0] = 0

for i in range(1, n+1):
    for j in range(1, n+1):
        if fp[i] <= sp[j]:
            # 둘 다 버렸을 때
            dp[i][j] = max(dp[i][j], dp[i-1][j-1])
            # 첫번째 플레이어만 버렸을 떄
            dp[i][j] = max(dp[i][j], dp[i-1][j])
        else:
            # 두번째 플레이어만 버렸을 때
            dp[i][j] = max(dp[i][j], dp[i][j-1]+sp[j])

print(dp[n][n])