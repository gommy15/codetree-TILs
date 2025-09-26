import sys

INT_MAX = sys.maxsize

n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

visited = [False] * n
course = [0] 

ans = INT_MAX

def calc():
    dist = 0
    for i in range(n - 1):
        if grid[course[i]][course[i+1]] == 0:
            return INT_MAX
        dist += grid[course[i]][course[i+1]]

    if grid[course[-1]][course[0]] == 0:
        return INT_MAX
    dist += grid[course[-1]][course[0]]
    return dist

def find_min_dist(cnt):
    global ans
    if cnt == n - 1:
        ans = min(ans, calc())
        return
    for i in range(1, n):
        if visited[i]:
            continue

        course.append(i)
        visited[i] = True
        find_min_dist(cnt+1)
        course.pop()
        visited[i] = False

visited[0] = True  
find_min_dist(0)
print(ans)
