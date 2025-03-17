from sortedcontainers import SortedSet

n = int(input())

ss = SortedSet()

for _ in range(n):
    command = input()

    if command.startswith("add"):
        x = int(command.split()[1])

        ss.add(x)
    elif command.startswith("remove"):
        x = int(command.split()[1])

        ss.remove(x)
    elif command.startswith("find"):
        x = int(command.split()[1])

        if x in ss:
            print("true")
        else:
            print("false")
    elif command.startswith("lower_bound"):
        x = int(command.split()[1])

        idx = ss.bisect_left(x)
        print(ss[idx] if idx < len(ss) else "None")
    elif command.startswith("upper_bound"):
        x = int(command.split()[1])

        idx = ss.bisect_right(x)
        print(ss[idx] if idx < len(ss) else "None")
    elif command.startswith("largest"):
        if ss:
            print(ss[-1])
        else:
            print("None")
    else:
        if ss:
            print(ss[0])
        else:
            print("None")
