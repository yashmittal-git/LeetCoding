class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        if len(ransomNote) > len(magazine):
            return False

        for char in ransomNote:
            if char not in magazine:
                return False
            magazine = magazine.replace(char,"",1)
        
        return True