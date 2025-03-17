from sortedcontainers import SortedSet

t = int(input())

for _ in range(t):
    k = int(input())

    ss = SortedSet()

    for _ in range(k):
        command = input()
        x = int(command.split()[1])

        if command.startswith("I"):
            ss.add(x)
        else:
            if ss:
                if x == 1:
                    ss.remove(ss[-1])
                else:
                    ss.remove(ss[0])
    
    if ss:
        print(ss[-1], ss[0])
    else:
        print("EMPTY")

