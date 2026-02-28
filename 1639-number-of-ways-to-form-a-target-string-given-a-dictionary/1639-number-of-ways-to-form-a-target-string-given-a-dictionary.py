class Solution:
        
    def numWays(self, words: List[str], target: str) -> int:
        freq = []
        for i in range(len(words[0])):
            freq.append([])
            for j in range(26):
                freq[i].append(0)
        for i in range(len(words)):
            for j in range(len(words[i])):
                char = words[i][j]
                freq[j][ord(char)-ord('a')] = freq[j][ord(char)-ord('a')] + 1
        
        dp = []
        for i in range(len(target)):
            dp.append([])
            for j in range(len(words[0])):
                dp[i].append(-1)


        def solve(i, j):
            if i ==len(target):
                return 1
            if j == len(words[0]):
                return 0
            if dp[i][j]!=-1:
                return dp[i][j]

            not_taken = solve(i, j+1)
            taken = freq[j][ord(target[i]) - ord('a')]*solve(i+1, j+1)
            dp[i][j] = taken+not_taken
            
            return dp[i][j]


        return solve(0,0) % (10**9 + 7)

        