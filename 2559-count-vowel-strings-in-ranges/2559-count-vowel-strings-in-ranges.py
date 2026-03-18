class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowelUntilIndex = [0]
        vowels = set(['a','e','i','o','u'])

        def checkword(word):
            if word[0] in vowels and word[-1] in vowels:
                return 1
            return 0

        for word in words:
            vowelUntilIndex.append(vowelUntilIndex[-1]+checkword(word))
        
        ans = []
        for query in queries:
            ans.append(vowelUntilIndex[query[1] + 1] - vowelUntilIndex[query[0]])
        return ans
        