def change(coins, value):
    n = len(coins)
    dp = [[float('inf')] * (value + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = 0

    for i in range(1, n + 1):
        for j in range(1, value + 1):
            if coins[i - 1] <= j:
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][value]


coins = [9, 6, 5, 1]
v = 11

print(change(coins, v))