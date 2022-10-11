# Базовым алгоритмом для сортировки слиянием является алгоритм слияния двух упорядоченных
# массивов в один упорядоченный массив. Эта операция выполняется за линейное время с линейным
# потреблением памяти. В качестве первого шага для написания сортировки слиянием Вам предстоит
# написать слияние двух массивов.

n = int(input())
p1 = list(map(int, input().split()))
k = int(input())
p2 = list(map(int, input().split()))
i = 0
j = 0
new = []
while i != len(p1) and j != len(p2):
    if p1[i] <= p2[j]:
        new.append(p1[i])
        i += 1
    elif p2[j] < p1[i]:
        new.append(p2[j])
        j += 1
if i == len(p1):
    new.extend(p2[j:])
elif j == len(p2):
    new.extend(p1[i:])
print(*new)
