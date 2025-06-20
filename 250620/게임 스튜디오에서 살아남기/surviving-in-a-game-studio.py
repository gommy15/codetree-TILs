MOD = 10**9 + 7

n = int(input())

dp = [[[0 for _ in range(4)] for _ in range(4)] for _ in range(n+1)]

dp[1][1][0] = 1
dp[1][0][1] = 1 
dp[1][0][0] = 1


for i in range(1, n):
    for j in range(3):
        for k in range(3):
            dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD
            dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD
            if k < 2:
                dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD

ans = 0
for j in range(3):
    for k in range(3):
        ans = (ans + dp[n][j][k]) % MOD

print(ans)


"""
MOD = 10**9 + 7

n = int(input())

dp = [[[0] * (4)] * (4)] * (n+1)

### 일자, T, B
dp[1][1][0] = 1
dp[1][0][1] = 1
dp[1][0][0] = 1


for i in range(1, n):
    for j in range(3):
        for k in range(3):
            # T 추가
            dp[i+1][j+1][0] = (dp[i+1][j+1][0] + dp[i][j][k])%MOD
            # G 추가
            dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][k])%MOD

            # B가 연속으로 나오는 경우
            if k<2:
                dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k])%MOD

ans = 0
for j in range(3):
    for k in range(3):
        ans = (ans + dp[n][j][k]) % MOD

print(ans)

"""