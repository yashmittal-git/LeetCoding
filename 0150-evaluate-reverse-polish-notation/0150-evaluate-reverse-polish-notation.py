class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            try:
                int(token)
                stack.append(token)
            except:
                elem2 = int(stack.pop())
                elem1 = int(stack.pop())
                
                elem = None
                if token == '+':
                    elem=elem1+elem2
                elif token == '-':
                    elem=elem1-elem2
                elif token == '*':
                    elem=elem1*elem2
                elif token == '/':
                    elem=elem1/elem2
                
                stack.append(elem)

        return int(stack.pop())
        