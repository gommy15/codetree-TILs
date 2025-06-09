k, n = tuple(map(int, input().split()))

seq = []

def seq_print():
    for s in seq:
        print(s, end=" ")

def get_seq(cnt):
    if cnt == n:
        seq_print()
        print()
        return
    
    for i in range(1, k+1):
        seq.append(i)
        get_seq(cnt + 1)
        seq.pop()

get_seq(0)