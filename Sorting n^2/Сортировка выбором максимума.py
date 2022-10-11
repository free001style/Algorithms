def choice_sort(lst):
    for i in range(len(lst) - 1, -1, -1):
        max_ind = i
        for j in range(i - 1, -1, -1):
            if lst[j] > lst[max_ind]:
                max_ind = j
        lst[max_ind], lst[i] = lst[i], lst[max_ind]
    return lst


n = int(input())
if n != 0:
    lst = list(map(int, input().split()))
    print(*choice_sort(lst))

