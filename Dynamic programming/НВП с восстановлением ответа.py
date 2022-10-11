n = int(input())
s1 = list(map(int, input().split()))
dp = [0] * n
for i in range(n):
    for j in range(i):
        if dp[j] > dp[i] and s1[i] > s1[j]:
            dp[i] = dp[j]
    dp[i] += 1
i = dp.index(max(dp))
ans = [s1[i]]
while dp[i] != 1:
    j = i - 1
    while dp[j] != dp[i] - 1 or s1[j] >= s1[i]:
        j -= 1
    i = j
    ans.append(s1[i])
print(' '.join(map(str, ans[::-1])))
