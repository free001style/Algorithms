troom, tcond = map(int, input().split())
mode = input()
if mode == 'freeze':
    if troom <= tcond:
        print(troom)
    else:
        print(tcond)
if mode == 'heat':
    if troom >= tcond:
        print(troom)
    else:
        print(tcond)
if mode == 'auto':
    print(tcond)
if mode == 'fan':
    print(troom)
