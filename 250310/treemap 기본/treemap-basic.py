from sortedcontainers import SortedDict

n = int(input())

sd = SortedDict()

for _ in range(n):
    command = input()

    if command.startswith("add"):
        _, k, v = tuple(command.split())

        sd[int(k)] = int(v)
    elif command.startswith("remove"):
        _, k = tuple(command.split())

        sd.pop(int(k))
    elif command.startswith("find"):
        _, k = tuple(command.split())

        if int(k) in sd:
            print(sd[int(k)])
        else:
            print("None")
    else:
        if sd:
            for _, v in sd.items():
                print(v, end = " ")
            print()
        else:
            print("None")