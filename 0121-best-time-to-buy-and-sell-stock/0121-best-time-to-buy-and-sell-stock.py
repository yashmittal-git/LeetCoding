class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        profit = 0
        minp = prices[0]
        maxp = prices[0]
        for price in prices:
            if price < minp:
                minp = price
                maxp = -1
                maxprofit = max(maxprofit, profit)
                profit = 0
            if price > maxp:
                maxp = price
                profit = maxp-minp
        
        return max(maxprofit,profit)


            
        