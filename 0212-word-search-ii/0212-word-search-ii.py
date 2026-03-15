class Trie:
    def __init__(self):
        self.children = {}
        self.word = None
    
    def add(self,word):
        curr = self
        for char in word:
            if char not in curr.children:
                curr.children[char] = Trie()
            curr = curr.children[char]
        curr.word = word
    
    def exists(self,word):
        curr = self
        for char in word:
            if char not in curr.children:
                return False
            curr = curr.children[char]
        return curr.word == word
    
    def checkWords(self, board, i, j, wordsfromij, curr = None):
        m = len(board)
        n = len(board[0])
        
        if not curr:
            curr = self
        
        letter = board[i][j]
        
        if letter not in curr.children:
            return
        
        if curr.children[letter].word is not None:
            wordsfromij.append(curr.children[letter].word)
            curr.children[letter].word = None
        
        directions = [(-1,0),(0,-1),(1,0),(0,1)]
        board[i][j] = "0"

        for direction in directions:
            i1 = i + direction[0]
            j1 = j + direction[1]
            if i1>=0 and i1 <m and j1 >=0 and j1 <n:
                self.checkWords(board, i1, j1, wordsfromij, curr.children[letter])
        
        board[i][j] = letter


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.add(word)
        
        m = len(board)
        n = len(board[0])

        ans = []

        for i in range(m):
            for j in range(n):
                if board[i][j] in trie.children:
                    trie.checkWords(board, i, j, ans)

        return ans
        