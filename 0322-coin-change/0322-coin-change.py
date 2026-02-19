class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        amounts = [amount + 1] * (amount + 1)
        amounts[0] = 0

        for i in range(amount + 1):
            for coin in coins:
                if i + coin <= amount:
                    amounts[i+coin] = min(amounts[i+coin],amounts[i]+1)
        
        return amounts[-1] if amounts[-1] != amount + 1 else -1

        