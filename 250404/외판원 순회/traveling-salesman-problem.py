import sys

INT_MAX = sys.maxsize

n = int(input())
grid = [
    list(map(int, input().split()))
    for _ in range(n)
]

visited = [False]*n
picked = []

ans = INT_MAX

def find_min(idx):
    global ans

    if idx == n:
        total_cost = 0
        for i in range(n-1):
            cur_cost = grid[picked[i]][picked[i+1]]

            if cur_cost == 0:
                return
            
            total_cost += cur_cost
        
        if grid[picked[-1]][0] == 0:
            return
        
        ans = min(ans, total_cost+grid[picked[-1]][0])
        return
    

    for i in range(n):
        if visited[i]:
            continue
        
        visited[i] = True
        picked.append(i)

        find_min(idx+1)

        visited[i] = False
        picked.pop()


visited[0] = True
picked.append(0)
find_min(1)

print(ans)