n = int(input())

dp = [0] * 20

dp[0] = dp[1] = 1

def bst_num(num):
    cnt = 0

    for i in range(num):
        cnt += dp[i]*dp[num-i-1]
    
    return cnt

for i in range(2, n+1):
    dp[i] = bst_num(i)

print(dp[n])