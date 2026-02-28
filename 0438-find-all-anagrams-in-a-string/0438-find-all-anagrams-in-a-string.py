class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []
        counts = [0]*26
        results = []

        for i in range(len(p)):
            pindex = ord(p[i])-ord('a')
            sindex = ord(s[i])-ord('a')
            counts[pindex] = counts[pindex] + 1
            counts[sindex] = counts[sindex] - 1


        l = 0
        r = len(p)

        def validAnagram():
            for count in counts:
                if count != 0:
                    return False
            return True

        while r < len(s):
            if validAnagram():
                results.append(l)
            
            lindex = ord(s[l]) - ord('a')
            rindex = ord(s[r]) - ord('a')
            counts[lindex] = counts[lindex] + 1
            counts[rindex] = counts[rindex] - 1
            l = l + 1
            r = r + 1

        if validAnagram():
            results.append(l)


        return results
            