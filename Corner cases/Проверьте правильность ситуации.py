#Напишите программу, которая по изображению поля для игры в «Крестики-нолики» определит,
# могла ли такая ситуация возникнуть в результате игры с соблюдением всех правил.Напомним,
# что игра в «Крестики-нолики» ведется на поле 3*3. Два игрока ходят по очереди. Первый
# ставит крестик, а второй – нолик. Ставить крестик и нолик разрешается в любую еще не
# занятую клетку поля. Когда один из игроков поставит три своих знака в одной горизонтали,
# вертикали или диагонали, или когда все клетки поля окажутся заняты, игра заканчивается.

a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
X_0 = [a, b, c]
X_0T = list(zip(a, b, c))
quan_1, quan_2 = 0, 0
diag1, diag2 = [X_0[0][0], X_0[1][1], X_0[2][2]], \
               [X_0[0][2], X_0[1][1], X_0[2][0]]
x_is_winner = False
O_is_winner = False
for i in range(3):
    for j in X_0[i]:
        if j == 1:
            quan_1 += 1
        elif j == 2:
            quan_2 += 1
for i in range(3):
    if set(X_0[i]) == {1} or set(X_0T[i]) == {1} or \
            set(diag1) == {1} or set(diag2) == {1}:
        x_is_winner = True
    elif set(X_0[i]) == {2} or set(X_0T[i]) == {2} or \
            set(diag1) == {2} or set(diag2) == {2}:
        O_is_winner = True
if quan_1 <= 5 and quan_2 <= 4 and (quan_1 == quan_2 or quan_1 == quan_2 + 1):
    if x_is_winner and O_is_winner:
        print('NO')
    elif not x_is_winner and not O_is_winner and quan_2 > quan_1:
        print('NO')
    elif x_is_winner and quan_1 <= quan_2:
        print('NO')
    elif O_is_winner and quan_1 != quan_2:
        print('NO')
    else:
        print('YES')
else:
    print('NO')
