# Требуется определить в заданном массиве номер самого левого
# и самого правого элемента, равного искомому числу.

import bisect

n = int(input())
lst = list(map(int, input().split()))
k = int(input())
list_x = list(map(int, input().split()))
for x in list_x:
    ind = bisect.bisect_left(lst, x)
    if ind >= len(lst):
        print(0, 0)
        continue
    elif lst[ind] == x:
        print(ind + 1, bisect.bisect(lst, x, ind))
    else:
        print(0, 0)
