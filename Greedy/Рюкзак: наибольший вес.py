# Дано N золотых слитков массой m1, …, mN. Ими наполняют рюкзак, который выдерживает вес не более M.
# Какую наибольшую массу золота можно унести в таком рюкзаке?

n, M = map(int, input().split())
gold_w = list(map(int, input().split()))
m = [0] * (M + 1)
prev = m[:]
for w in gold_w:
    for c in range(M + 1):
        m[c] = prev[c] if w > c else max(prev[c], prev[c - w] + w)
    prev, m = m, prev
print(prev[-1])
