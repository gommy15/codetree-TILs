import sys

INT_MAX = sys.maxsize

n = int(input())

grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False] * (n+1)
course = [1]

ans = INT_MAX

def calc():
    dist = 0

    for i in range(n):
        dist += grid[course[i]-1][course[i+1]-1]
    
    dist += grid[course[n]-1][0]

    return dist

def find_min_dist(cnt):
    global ans

    if cnt == n:
        ans = min(ans, calc())
        return
    
    for i in range(1, n+1):
        if visited[i]:
            continue
        
        course.append(i)
        visited[i] = True

        find_min_dist(cnt+1)

        course.pop()
        visited[i] = False

find_min_dist(0)

print(ans)