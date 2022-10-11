# Требуется реализовать алгоритм, который принимает на вход три последовательности
# отсортированных по возрастанию натуральных чисел от 0 до 109 и возвращает в
# качестве результата одну отсортированную последовательность, состоящую из тех
# чисел, что были во входных последовательностях.

def merge_sort(a, b):
    i = 0
    j = 0
    new = []
    while i != len(a) and j != len(b):
        if a[i] <= b[j]:
            new.append(a[i])
            i += 1
        elif b[j] < a[i]:
            new.append(b[j])
            j += 1
        if i == len(a):
            new.extend(b[j:])
        elif j == len(b):
            new.extend(a[i:])
    return new


n = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
print(*merge_sort(a, merge_sort(b, c)))
