# В игре в пьяницу карточная колода раздается поровну двум игрокам. Далее они вскрывают по одной
# верхней карте, и тот, чья карта старше, забирает себе обе вскрытые карты, которые кладутся под
# низ его колоды. Тот, кто остается без карт – проигрывает. Для простоты будем считать, что все
# карты различны по номиналу, а также, что самая младшая карта побеждает самую старшую карту
# ("шестерка берет туза"). Игрок, который забирает себе карты, сначала кладет под низ своей колоды
# карту первого игрока, затем карту второго игрока (то есть карта второго игрока оказывается внизу колоды).
# Напишите программу, которая моделирует игру в пьяницу и определяет, кто выигрывает. В игре участвует 10 карт,
# имеющих значения от 0 до 9, большая карта побеждает меньшую, карта со значением 0 побеждает карту 9.

from collections import deque

first = deque(map(int, input().split()))
second = deque(map(int, input().split()))
quan = 0
while len(first) != 0 and len(second) != 0:
    if first[0] == 9 and second[0] == 0:
        second.append(first.popleft())
        second.append(second.popleft())
        quan += 1
        continue
    elif first[0] == 0 and second[0] == 9:
        first.append(first.popleft())
        first.append(second.popleft())
        quan += 1
        continue
    elif first[0] > second[0]:
        first.append(first.popleft())
        first.append(second.popleft())
    elif first[0] < second[0]:
        second.append(first.popleft())
        second.append(second.popleft())
    quan += 1
if quan >= 10 ** 6:
    print('botva')
else:
    if len(first) == 0:
        print(f'second {quan}')
    elif len(second) == 0:
        print(f'first {quan}')
