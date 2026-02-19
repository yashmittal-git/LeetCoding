class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        uniques = set()
        i = 0
        j = 0
        n = len(s)
        longestLength = 0

        while j < n and i < n:
            if s[j] not in uniques:
                uniques.add(s[j])
                j = j + 1
            else:
                longestLength = max(longestLength, len(uniques))
                uniques.remove(s[i])
                i = i + 1
        return max(longestLength,len(uniques))

        