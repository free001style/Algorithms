def merge_sort(lst):
    if len(lst) > 1:
        left = lst[:len(lst) // 2]
        right = lst[len(lst) // 2:]
        merge_sort(left)
        merge_sort(right)
        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                lst[k] = left[i]
                i += 1
            elif right[j] < left[i]:
                lst[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            lst[k] = left[i]
            i = i + 1
            k = k + 1

        while j < len(right):
            lst[k] = right[j]
            j = j + 1
            k = k + 1
    return lst


n = int(input())
lst = list(map(int, input().split()))
print(*merge_sort(lst))
