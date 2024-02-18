from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxReturn = 0
        localMax = 0
        for i in range(1, len(prices)):
            localMax = max(0, localMax + prices[i] - prices[i-1])
            maxReturn = max(localMax, maxReturn)

        return maxReturn
