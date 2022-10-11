n = int(input())
s1 = input().split()
m = int(input())
s2 = input().split()
dp = [[0] * (m + 1) for i in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if s1[i - 1] == s2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
ans = []
while n > 0 and m > 0:
    if s1[n - 1] == s2[m - 1]:
        ans.append(s1[n - 1])
        n -= 1
        m -= 1
    elif dp[n - 1][m] == dp[n][m]:
        n -= 1
    else:
        m -= 1
print(' '.join(list(ans[::-1])))
