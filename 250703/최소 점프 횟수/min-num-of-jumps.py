import sys
INT_MAX = sys.maxsize

n  = int(input())
arr = list(map(int, input().split()))

ans = INT_MAX

def find_min_jump(idx, cnt):
    global ans

    if idx >= n-1:
        ans = min(ans, cnt)
        return
    
    if arr[idx] == 0:
        return

    for i in range(1, arr[idx]+1):
        find_min_jump(idx+i, cnt+1)


find_min_jump(0, 0)
print(ans if ans != INT_MAX else -1)