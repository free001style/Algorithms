#Решите в целых числах уравнение:(ax+b)^0.5=c

a, b, c = int(input()), int(input()), int(input())
if a != 0 and c >= 0 and \
        abs(int((c ** 2 - b) / a) - (c ** 2 - b) / a) <= 10 ** -6:
    print(int((c ** 2 - b) / a))
elif c >= 0 and b == c ** 2 and a == 0:
    print('MANY SOLUTIONS')
else:
    print('NO SOLUTION')

