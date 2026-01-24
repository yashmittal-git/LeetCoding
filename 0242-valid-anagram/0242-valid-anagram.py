class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        charcount = {}
        for char in s:
            charcount[char] = charcount.get(char,0) + 1
        
        for char in t:
            charcount[char] = charcount.get(char,0) - 1
        
        for char in charcount.items():
            if char[1] != 0:
                return False

        return True


        