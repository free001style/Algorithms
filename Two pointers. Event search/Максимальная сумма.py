# В этой задаче вам требуется найти непустой отрезок массива с максимальной суммой.

n = int(input())
lst = list(map(int, input().split()))
sum = 0
ans = 0
for i in lst:
    sum += i
    if sum > ans:
        ans = sum
    elif sum < 0:
        sum = 0
if ans == 0:
    print(max(lst))
else:
    print(ans)
