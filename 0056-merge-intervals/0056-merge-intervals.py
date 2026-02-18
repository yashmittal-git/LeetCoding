class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        intervals.sort(key = lambda x:x[0])
        merged = []
        merged.append(intervals[0])

        for i in range(1,len(intervals)):
            curr = merged[-1]
            nxt = intervals[i]
            if nxt[0]<=curr[1]:
                curr[1] = max(curr[1],nxt[1])
            else:
                merged.append(nxt)
        
        return merged

        