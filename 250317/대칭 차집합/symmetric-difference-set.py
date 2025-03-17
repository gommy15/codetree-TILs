na, nb = tuple(map(int, input().split()))

a = list(map(int, input().split()))
b = list(map(int, input().split()))

sa = set()
sb = set()

for x in a:
    sa.add(x)

for y in b:
    sb.add(y)

ans = set()

for x in a:
    if x not in sb:
        ans.add(x)

for y in b:
    if y not in sa:
        ans.add(y)

print(len(ans))