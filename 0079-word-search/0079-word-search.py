class Solution:
    def checkExists(self, board, word, i, j, charCount):
        if charCount == len(word):
            return True
        if i >= len(board) or i < 0 or j >= len(board[0]) or j < 0:
            return False
        if board[i][j] == word[charCount] and not board[i][j]=='0':
            prev = board[i][j]
            board[i][j] = '0'
            result = self.checkExists(board, word, i+1, j, charCount + 1) or\
                    self.checkExists(board, word, i-1, j, charCount + 1) or\
                    self.checkExists(board, word, i, j+1, charCount + 1) or\
                    self.checkExists(board, word, i, j-1, charCount + 1)
            board[i][j] = prev
            return result
        return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.checkExists(board, word, i, j, 0):
                        return True
        return False