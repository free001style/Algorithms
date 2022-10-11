# Рассмотрим последовательность целых чисел длины n. По ней с шагом 1 двигается «окно»
# длины k, то есть сначала в «окне» видны первые k чисел, на следующем шаге в «окне»
# уже будут находиться k чисел, начиная со второго, и так далее до конца последовательности.
# Требуется для каждого положения «окна» определить минимум в нём.

n, k = map(int, input().split())
posl = list(map(int, input().split()))
stack = []
need_el = 0
answer = []
for i in range(len(posl)):
    while len(stack) > need_el and posl[stack[-1]] >= posl[i]:
        stack.pop()
    stack.append(i)
    if i >= k - 1:
        answer.append(posl[stack[need_el]])
        if i - stack[need_el] >= k - 1:
            need_el += 1
    if need_el > k:
        stack = stack[k:]
        need_el -= k
for i in answer:
    print(i)

