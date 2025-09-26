import sys

INT_MAX = sys.maxsize

n = int(input())
arr = list(map(int, input().split()))

ans = INT_MAX

def find_min_diff(idx, cnt, diff):
    global ans

    if idx == 2*n:
        if cnt == n:
            ans = min(ans, abs(diff))
        return
    
    find_min_diff(idx+1, cnt+1, diff+arr[idx])
    find_min_diff(idx+1, cnt, diff-arr[idx])

find_min_diff(0, 0, 0)

print(ans)