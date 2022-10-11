# Витя работает недалеко от одной из станций кольцевой линии Московского метро, а живет рядом с другой
# станцией той же линии. Требуется выяснить, мимо какого наименьшего количества промежуточных станций
# необходимо проехать Вите по кольцу, чтобы добраться с работы домой.

from math import floor

quan, first_st, last_st = map(int, input().split())
if abs(last_st - first_st) - 1 < floor(quan / 2):
    print(abs(last_st - first_st) - 1)
else:
    print(quan - abs(last_st - first_st) - 1)
