








































from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        index = 0
        numCoin = 0
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for val in range(1, amount + 1):
            for index in range(len(coins)):
                if coins[index] <= val:
                    dp[val] = min(dp[val], dp[val - coins[index]] + 1)

        if dp[amount] > amount:
            return -1
        else:
            return dp[amount]
