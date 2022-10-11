n = int(input())
lst = list(map(int, input().split()))
for i in range(1, len(lst)):
    flag = False
    for j in range(i, 0, -1):
        if lst[j] < lst[j - 1]:
            lst[j], lst[j - 1] = lst[j - 1], lst[j]
            flag = True
    if flag:
        print(*lst)
