class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        if len(ransomNote) > len(magazine):
            return False

        letterCount = [0] * 26

        for char in magazine:
            letterCount[ord(char) - ord('a')] += 1
        
        for char in ransomNote:
            letterCount[ord(char) - ord('a')] -= 1
            if letterCount[ord(char) - ord('a')] < 0:
                return False
        
        return True