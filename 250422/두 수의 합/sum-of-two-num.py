n, m = tuple(map(int, input().split()))

stoi = dict()
itos = dict()

for i in range(1, n+1):
    st = input()
    stoi[st] = i
    itos[chr(i)] = st

for i in range(m):
    inp = input()

    if '0' <= inp[0] <= '9':
        print(itos[inp])
    else:
        print(stoi[inp])

