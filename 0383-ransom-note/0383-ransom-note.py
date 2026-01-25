class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        
        charcount = {}
        for char in magazine:
            charcount[char] = charcount.get(char,0) + 1
        for char in ransomNote:
            charcount[char] = charcount.get(char,0) - 1
            if charcount[char] < 0:
                return False
        

        return True        