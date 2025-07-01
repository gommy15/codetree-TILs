k, n = tuple(map(int, input().split()))

seq = []

def Print():
    for s in seq:
        print(s, end=" ")

def find_seq(cnt):
    if cnt == n:
        Print()
        print()
        return
    
    for i in range(1, k+1):
        seq.append(i)
        find_seq(cnt+1)
        seq.pop()

find_seq(0)