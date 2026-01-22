class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        combinations = {
            ")":"(",
            "}":"{",
            "]":"["
        }

        for char in s:
            if char in ["{","[","("]:
                stack.append(char)
            else:
                if len(stack) == 0 or combinations[char] != stack.pop():
                    return False
        
        if len(stack) == 0:
            return True
        
        return False
        