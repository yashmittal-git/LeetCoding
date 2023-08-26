class Solution:
    def getClosingParenthesis(char):
        if char == '(':
            return ')'
        elif char == '{':
            return '}'
        elif char == '[':
            return ']'

    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char == '(' or char == '{' or char == '[' :
                stack.append(char)
            else:
                if not len(stack) or char != Solution.getClosingParenthesis(stack[-1]):
                    return False
                else:
                    stack.pop()
        if not len(stack):
            return True
        return False

