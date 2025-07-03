import sys

INT_MAX = sys.maxsize

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False]*n
picked = []
ans = 0

def calc():
    min_val = INT_MAX

    for i in range(n):
        min_val = min(min_val, grid[i][picked[i]])
    
    return min_val

def find_min_max(cnt):
    global ans
    
    if cnt == n:
        ans = max(ans, calc())
        return
    
    for i in range(n):
        if visited[i]:
            continue
        
        picked.append(i)
        visited[i] = True

        find_min_max(cnt + 1)

        visited[i] = False
        picked.pop()


find_min_max(0)
print(ans)