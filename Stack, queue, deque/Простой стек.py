stack = []
while True:
    try:
        comm = input().split()
        if 'push' in comm:
            stack.append(int(comm[-1]))
            print('ok')
            comm.clear()
            continue
        elif 'pop' in comm:
            print(stack.pop())
            comm.clear()
            continue
        elif 'back' in comm:
            print(stack[-1])
            comm.clear()
            continue
        elif 'size' in comm:
            print(len(stack))
            comm.clear()
            continue
        elif 'clear' in comm:
            stack.clear()
            print('ok')
            comm.clear()
            continue
        elif 'exit' in comm:
            print('bye')
            break
    except EOFError:
        break
