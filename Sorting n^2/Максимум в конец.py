# Выведите результат постановки максимального элемента на последнюю позицию,
# то есть N целых чисел, разделяя их пробелами.

def choice_sort(lst):
    max_ind = 0
    for i in range(1, len(lst)):
        if lst[i] > lst[max_ind]:
            max_ind = i
    lst[-1], lst[max_ind] = lst[max_ind], lst[-1]
    return lst


n = int(input())
if n != 0:
    print(*choice_sort(list(map(int, input().split()))))

