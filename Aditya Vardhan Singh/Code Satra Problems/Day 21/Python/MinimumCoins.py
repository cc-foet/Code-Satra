def minCoins(coins, V):
    dp = [float('inf')] * (V+1)
    dp[0] = 0

    for i in range(1, V+1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[V] if dp[V] != float('inf') else -1

coins = [9,6,5,1]
V = 11
print(minCoins(coins, V))
