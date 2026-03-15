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
    
    def checkWords(self, board, i, j, wordsfromij, visited = None, curr = None):
        m = len(board)
        n = len(board[0])

        if not visited:
            visited = [[False for _ in range(n)] for _ in range(m)]
        
        if not curr:
            curr = self
        
        if visited[i][j] or board[i][j] not in curr.children:
            return False
        
        if curr.children[board[i][j]].word is not None:
            wordsfromij.append(curr.children[board[i][j]].word)
        
        directions = [(-1,0),(0,-1),(1,0),(0,1)]
        visited[i][j] = True

        for direction in directions:
            i1 = i + direction[0]
            j1 = j + direction[1]
            if i1>=0 and i1 <m and j1 >=0 and j1 <n:
                self.checkWords(board, i1, j1, wordsfromij, visited, curr.children[board[i][j]])
        
        visited[i][j] = False


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.add(word)
        
        m = len(board)
        n = len(board[0])

        ans = set()

        for i in range(m):
            for j in range(n):
                if board[i][j] in trie.children:
                    wordsfromij = []
                    trie.checkWords(board, i, j, wordsfromij)
                    for word in wordsfromij:
                        ans.add(word)

        return list(ans)
        