class MinStack:

    def __init__(self):
        self._stack = []
        self._minstack = []

    def push(self, val: int) -> None:
        if not self._minstack or self._minstack[-1] >= val:
            self._minstack.append(val)
        self._stack.append(val) 
        

    def pop(self) -> None:
        if self._minstack[-1] == self._stack[-1]:
            self._minstack.pop()
        self._stack.pop()

    def top(self) -> int:
        return self._stack[-1]

    def getMin(self) -> int:
        return self._minstack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()