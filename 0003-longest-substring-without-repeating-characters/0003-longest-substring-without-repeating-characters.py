class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        i, j = 0, 0
        charSet = set()
        longestSubstringLen = 0
        while i < n and j < n:
            if s[j] in charSet:
                if longestSubstringLen < len(charSet):
                    longestSubstringLen = len(charSet)
                charSet.remove(s[i])
                i = i + 1
            else:
                charSet.add(s[j])
                j = j + 1
            
        return max(len(charSet), longestSubstringLen)


        