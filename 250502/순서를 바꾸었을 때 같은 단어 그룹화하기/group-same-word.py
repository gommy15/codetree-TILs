n = int(input())

words = dict()
ans = 0

for _ in range(n):
    st = input()
    st = sorted(st)

    string = ""

    for elem in st:
        string += elem

    if string in words:
        words[string] += 1
    else:
        words[string] = 1


print(max(list(words.values())))


