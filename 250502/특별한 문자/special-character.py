import sys

st = input()

cnt = dict()

for c in st:
    if c in cnt:
        cnt[c] += 1
    else:
        cnt[c] = 1


for c in st:
    if cnt[c] == 1:
        print(c)
        sys.exit()

print("None")