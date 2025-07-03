import sys
INT_MAX = sys.maxsize

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False]*n
course = []
ans = INT_MAX


def find_min_cost(cnt):
    global ans

    if cnt == n:
        total_cost = 0
        course.append(0)

        for i in range(n):
            cur_cost = grid[course[i]][course[i+1]]

            if cur_cost == 0:
                course.pop()
                return

            total_cost += cur_cost

        ans = min(ans, total_cost)
        course.pop()
        return
    
    for i in range(n):
        if visited[i]:
            continue
        
        course.append(i)
        visited[i] = True

        find_min_cost(cnt+1)

        visited[i] = False
        course.pop()


visited[0] = True
course.append(0)
find_min_cost(1)
print(ans)
