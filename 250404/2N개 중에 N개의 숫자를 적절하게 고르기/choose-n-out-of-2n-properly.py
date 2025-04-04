import sys

INT_MAX = sys.maxsize

n = int(input())
num = list(map(int, input().split()))

ans = INT_MAX

def find_min(idx, cnt, diff):
    global ans

    if idx == 2*n:
        if cnt == n:
            ans = min(ans, abs(diff))
        return
    
    find_min(idx+1, cnt+1, diff+num[idx])
    find_min(idx+1, cnt, diff-num[idx])


find_min(0, 0, 0)
print(ans)