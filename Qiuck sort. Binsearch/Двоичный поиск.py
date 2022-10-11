def bin_search(lst, x):
    n = len(lst)
    l, r = 0, n - 1
    while r >= l:
        m = (l + r) // 2
        if lst[m] < x:
            l = m + 1
        elif lst[m] > x:
            r = m - 1
        else:
            return m
    return


n, k = list(map(int, input().split()))
lst = list(map(int, input().split()))
x_list = list(map(int, input().split()))
for x in x_list:
    znac = bin_search(lst, x)
    if znac is not None:
        print('YES')
    else:
        print('NO')
