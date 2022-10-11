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
            if len(stack) > 0:
                print(stack.pop())
                comm.clear()
                continue
            else:
                print('error')
                continue
        elif 'back' in comm:
            if len(stack) > 0:
                print(stack[-1])
                comm.clear()
                continue
            else:
                print('error')
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
