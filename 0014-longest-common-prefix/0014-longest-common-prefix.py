class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]

        for i in range(1,len(strs)):
            matchIndex = 0
            
            for j in range(min(len(prefix),len(strs[i]))):
                if prefix[j] == strs[i][j]:
                    matchIndex += 1
                else:
                    break

            if matchIndex == 0:
                return ""
            prefix = prefix[:matchIndex]

        return prefix


