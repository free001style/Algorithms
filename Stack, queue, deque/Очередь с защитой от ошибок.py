from collections import deque

queue = deque()
while True:
    try:
        comm = input().split()
        if 'push' in comm:
            queue.append(int(comm[-1]))
            print('ok')
            comm.clear()
            continue
        elif 'pop' in comm:
            if len(queue) > 0:
                print(queue.popleft())
                comm.clear()
                continue
            else:
                print('error')
                continue
        elif 'front' in comm:
            if len(queue) > 0:
                print(queue[0])
                comm.clear()
                continue
            else:
                print('error')
                continue
        elif 'size' in comm:
            print(len(queue))
            comm.clear()
            continue
        elif 'clear' in comm:
            queue.clear()
            print('ok')
            comm.clear()
            continue
        elif 'exit' in comm:
            print('bye')
            break
    except EOFError:
        break

