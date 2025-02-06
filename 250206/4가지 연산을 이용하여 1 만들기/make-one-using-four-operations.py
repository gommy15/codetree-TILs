from collections import deque
import sys

OPE_NUM = 4
INT_MAX = sys.maxsize

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
        return num -1
    elif op == 1:
        return num + 1
    elif op == 2:
        return num//2
    else:
        return num//3

def can_go(num):
    return 1<=num<=2*n-1 and not visited[num]

def find_min():
    global ans
    
    while q:
        cur_num = q.popleft()

        for i in range(OPE_NUM):
            if not possible(cur_num, i):
                continue
            
            new_num = calculate(cur_num, i)

            if can_go(new_num):
                q.append(new_num)
                visited[new_num] = True
                step[new_num] = step[cur_num]+1
        
        ans = step[1]

q.append(n)
visited[n] = True
step[n] = 0

find_min()
print(ans)