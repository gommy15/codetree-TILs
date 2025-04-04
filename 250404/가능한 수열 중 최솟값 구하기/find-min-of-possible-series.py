import sys

n = int(input())
numbers = [4, 5, 6]

series = []

def is_possible():
    length = 1

    while True:
        s1, e1 = len(series) - length, len(series)-1
        s2, e2 = s1-length, s1-1

        if s2<0:
            break

        if series[s1:e1+1] == series[s2:e2+1]:
            return False
        
        length += 1
    
    return True

def find_min_series(cnt):
    if cnt == n:
        for elem in series:
            print(elem, end = "")
        sys.exit(0)

    for number in numbers:
        series.append(number)

        if is_possible():
            find_min_series(cnt+1)
        series.pop()

find_min_series(0)