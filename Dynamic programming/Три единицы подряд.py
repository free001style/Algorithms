# По данному числу N определите количество последовательностей из нулей и единиц длины N,
# в которых никакие три единицы не стоят рядом.

from functools import lru_cache


@lru_cache()
def one(n):
    if n == 1:
        return 2
    elif n == 2:
        return 4
    elif n == 3:
        return 7
    else:
        return one(n - 1) + one(n - 2) + one(n - 3)


print(one(int(input())))
