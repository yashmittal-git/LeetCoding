class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        buyprice = prices[0]
        for price in prices:

            if price < buyprice:
                buyprice = price
            elif profit < price - buyprice:
                profit = price - buyprice
        
        return profit


            
        