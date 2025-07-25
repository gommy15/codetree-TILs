from collections import deque

n = int(input())

visited = [-1]*(2*n)

q = deque()

def is_possible(num, op):
    if op == 0:
        return num > 0
    elif op == 1:
        return True
    elif op == 2:
        return num % 2 == 0
    else:
        return num % 3 == 0

def calc(num, op):
    if op == 0:
        return num-1
    elif op == 1:
        return num+1
    elif op == 2:
        return num//2
    else:
        return num//3

def bfs():
    while q:
        num = q.popleft()

        for i in range(4):
            if is_possible(num, i):
                tmp = calc(num, i)
                if 1 <= tmp < 2*n and visited[tmp] == -1:
                    visited[tmp] = visited[num]+1
                    q.append(tmp)


visited[n] = 0
q.append(n)
bfs()

print(visited[1])