class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxi = 0
        
        left, right = 0, 1
        while right < len(prices):
            profit = prices[right] - prices[left]
            maxi = max(maxi, profit)
            
            if profit < 0:
                left = right
            right += 1
        
        return maxi