class TrieNode:
    def __init__(self, is_end=False):
        self.children = [None for _ in range(26)]
        self.is_end = is_end
ORD_A = 97

class Trie:

    def __init__(self):
        self.node = TrieNode()

    def insert(self, word: str) -> None:
        node = self.node
        for i in range(len(word)):
            char = word[i]
            if not node.children[ord(char)-ORD_A]:
                node.children[ord(char)-ORD_A] = TrieNode()
            node = node.children[ord(char)-ORD_A]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self.node
        for i in range(len(word)):
            char = word[i]
            if not node.children[ord(char)-ORD_A]:
                return False
            node = node.children[ord(char)-ORD_A]
        return node.is_end
        

    def startsWith(self, prefix: str) -> bool:
        node = self.node
        for i in range(len(prefix)):
            char = prefix[i]
            if not node.children[ord(char)-ORD_A]:
                return False
            node = node.children[ord(char)-ORD_A]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)