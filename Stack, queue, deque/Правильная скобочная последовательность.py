psp = input()
stack = []
eth_ok = True
for braket in psp:
    if braket in '({[':
        stack.append(braket)
    elif braket in ')}]':
        if len(stack) != 0:
            a = stack.pop()
            if a == '(' and braket == ')':
                continue
            elif a == '{' and braket == '}':
                continue
            elif a == '[' and braket == ']':
                continue
            else:
                eth_ok = False
                break
        else:
            eth_ok = False
            break
if eth_ok and len(stack) == 0:
    print('yes')
else:
    print('no')
