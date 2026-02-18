class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n+1)
        dp[0] = True
        wordset = set(wordDict)
        for i in range(0,n+1):
            for word in wordDict:
                if dp[i] and s[i:i+len(word)] == word:
                    dp[i+len(word)] = True
        return dp[-1]
        