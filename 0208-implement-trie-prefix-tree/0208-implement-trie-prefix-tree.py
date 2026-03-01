class TrieNode:
    def __init__(self, is_end=False):
        self.children = [None for _ in range(26)]
        self.is_end = is_end

class Trie:

    def __init__(self):
        self.node = TrieNode()

    def insert(self, word: str) -> None:
        node = self.node
        for i in range(len(word)):
            char = word[i]
            if not node.children[ord(char)-ord('a')]:
                node.children[ord(char)-ord('a')] = TrieNode()
            node = node.children[ord(char)-ord('a')]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.node
        for i in range(len(word)):
            char = word[i]
            if node.children[ord(char)-ord('a')]:
                node = node.children[ord(char)-ord('a')]
            else:
                return False
        if node.is_end != True:
            return False        
        return True
        

    def startsWith(self, prefix: str) -> bool:
        node = self.node
        for i in range(len(prefix)):
            char = prefix[i]
            if node.children[ord(char)-ord('a')]:
                node = node.children[ord(char)-ord('a')]
            else:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)