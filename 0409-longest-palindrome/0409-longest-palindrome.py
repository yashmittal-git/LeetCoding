class Solution:
    def longestPalindrome(self, s: str) -> int:
        letterCount = [0]*52
        for char in s:
            letterCount[ord(char) - ord('a')] += 1

        longestPalindrome = 0
        oddPresent = False
        for count in letterCount:
            if count%2 == 0:
                longestPalindrome += count
            else:
                oddPresent = True
                longestPalindrome += (count - 1)
            
        return longestPalindrome + 1 if oddPresent else longestPalindrome
                