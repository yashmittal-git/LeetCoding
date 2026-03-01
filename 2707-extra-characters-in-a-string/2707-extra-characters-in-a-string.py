class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        words = set(dictionary)
        print(words)
        dp = [[51 for _ in range(len(s) + 1)] for _ in range(len(s) + 1)]

        def minExtraCharIndex(i, j):
            if dp[i][j] != 51:
                return dp[i][j]
            if s[i:j] in words:
                return 0
            if i == j-1:
                return 1
            minExtra = 1 + minExtraCharIndex(i+1,j)
            for idx in range(i+1,j):
                minExtra = min(minExtra, minExtraCharIndex(i,idx) + minExtraCharIndex(idx,j))
            print(i,j,minExtra)
            dp[i][j] = minExtra
            return minExtra

        return minExtraCharIndex(0,len(s))
        