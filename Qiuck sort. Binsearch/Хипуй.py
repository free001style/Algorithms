# В этой задаче вам необходимо самостоятельно (не используя соответствующие классы и функции
# стандартной библиотеки) организовать структуру данных Heap для хранения целых чисел, над
# которой определены следующие операции: a) Insert(k) – добавить в Heap число k ; b) Extract
# достать из Heap наибольшее число (удалив его при этом).

# TL16

n = int(input())
heap = []
while True:
    try:
        com = list(map(int, input().split()))
        if com[0] == 0:
            if len(heap) == 0:
                heap.append(int(com[-1]))
                max_heap = com[-1]
            else:
                if max_heap < com[-1]:
                    heap.append(com[-1])
                    max_heap = com[-1]
                else:
                    heap.append(com[-1])
                    heap[-2], heap[-1] = heap[-1], heap[-2]
            com.clear()
            continue
        elif com[0] == 1:
            com.clear()
            print(heap.pop())
            max_ind = 0
            if len(heap) > 1:
                for i in range(1, len(heap)):
                    if heap[i] > heap[max_ind]:
                        max_ind = i
                heap[max_ind], heap[-1] = heap[-1], heap[max_ind]
                max_heap = heap[-1]
            elif len(heap) == 1:
                max_heap = heap[-1]
    except EOFError:
        break
