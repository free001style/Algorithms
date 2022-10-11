# В этой задаче Вам требуется найти максимальную по длине подстроку данной строки, такую что каждый
# символ встречается в ней не более k раз.

n, k = map(int, input().split())
lst = input()
db = dict.fromkeys(lst, 0)
i = 0
j = 0
l_ans = 0
r_ans = 0
while j < n:
    if db[lst[j]] < k:
        if j - i > r_ans - l_ans:
            r_ans, l_ans = j, i
        db[lst[j]] += 1
        j += 1
    else:
        i = j - k + 1
        db = dict.fromkeys(db.keys(), 0)
print(r_ans - l_ans + 1, l_ans + 1)
