n = int(input())

MAX_NUM = 19

dp = [0 for _ in range(MAX_NUM+1)]

def get_bst(num):
    cnt = 0

    for i in range(num):
        cnt += dp[i] * dp[num-i-1]

    return cnt

dp[0] = dp[1] = 1


for i in range(2, n+1):
    dp[i] = get_bst(i)

print(dp[n])