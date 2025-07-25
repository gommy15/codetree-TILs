import sys
INT_MAX = sys.maxsize

n = int(input())
graph = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False]*n
course = []

ans = INT_MAX

def calc():
    total_cost = 0
    
    for i in range(n):
        cur = graph[course[i]][course[i+1]]

        if cur == 0:
            return INT_MAX
        
        total_cost += cur
    
    return total_cost

def find_min(cnt):
    global ans

    if cnt == n:
        course.append(0)
        ans = min(ans, calc())
        course.pop()
        return
    
    for i in range(n):
        if visited[i]:
            continue
        
        course.append(i)
        visited[i] = True
        find_min(cnt+1)
        visited[i] = False
        course.pop()




visited[0] = True
course.append(0)
find_min(1)

print(ans)