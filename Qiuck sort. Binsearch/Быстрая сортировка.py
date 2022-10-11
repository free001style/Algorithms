def partition(lst, low, high):
    x = lst[(low + high) // 2]
    i = low - 1
    j = high + 1
    while True:
        i += 1
        while lst[i] < x:
            i += 1
        j -= 1
        while lst[j] > x:
            j -= 1
        if i >= j:
            return j
        lst[i], lst[j] = lst[j], lst[i]


def quick_sort(nums):
    def _quick_sort(items, low, high):
        if low < high:
            part = partition(items, low, high)
            _quick_sort(items, low, part)
            _quick_sort(items, part + 1, high)

    _quick_sort(nums, 0, len(nums) - 1)


n = int(input())
lst = list(map(int, input().split()))
quick_sort(lst)
print(*lst)
