from collections import deque
import sys

INT_MAX = sys.maxsize
OP_NUM = 4

n = int(input())
ans = INT_MAX

q = deque()
visited = [False for _ in range(2*n)]

step = [0 for _ in range(2*n)]

def possible(num, op):
    if op == 0 or op == 1:
        return True
    elif op == 2:
        return num%2 == 0
    else:
        return num%3 == 0

def calculate(num, op):
    if op == 0:
        return num-1
    elif op == 1:
        return num+1
    elif op == 2:
        return num//2
    else:
        return num//3

def can_go(num):
    return 1<=num<=2*n-1 and not visited[num]


def find_min():
    while q:
        cur_n = q.popleft()

        for i in range(OP_NUM):
            if not possible(cur_n, i):
                continue
            
            new_n = calculate(cur_n, i)

            if can_go(new_n):
                q.append(new_n)
                visited[new_n] = True
                step[new_n] = step[cur_n]+1

q.append(n)
visited[n] = True
step[n] = 0

find_min()
print(step[1])