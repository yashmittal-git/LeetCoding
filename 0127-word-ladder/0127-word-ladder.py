class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        alphabets = "qwertyuiopasdfghjklzxcvbnm"
        wordSet = set(wordList)
        length = 1
        q = [beginWord]
        while q:
            nq = []
            while q:
                word = q.pop()
                for i, char in enumerate(word):
                    for letter in alphabets:
                        if letter != char:
                            newWord = word[:i] + letter + word[i+1:]
                            if newWord == endWord:
                                return length + 1
                            if newWord in wordSet:
                                wordSet.remove(newWord)
                                nq.append(newWord)
            q = nq
            length = length + 1
        return 0