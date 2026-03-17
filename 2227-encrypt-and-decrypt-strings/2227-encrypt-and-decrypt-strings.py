class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.dictmap = defaultdict(int)
        self.keys = {}
        for i in range(len(keys)):
            self.keys[keys[i]] = values[i]
        
        for word in dictionary:
            enc = self.encrypt(word)
            self.dictmap[enc] = self.dictmap[enc] + 1


    def encrypt(self, word1: str) -> str:
        ans = ""
        for char in word1:
            if char not in self.keys:
                return ""
            ans = ans + self.keys[char]
        return ans

    def decrypt(self, word2: str) -> int:
        return self.dictmap[word2]


# Your Encrypter object will be instantiated and called as such:
# obj = Encrypter(keys, values, dictionary)
# param_1 = obj.encrypt(word1)
# param_2 = obj.decrypt(word2)