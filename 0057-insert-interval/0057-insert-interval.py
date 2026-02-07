class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        i = 0
        n = len(intervals)
        finalIntervals = []
        while i < n and intervals[i][1] < newInterval[0]:
            finalIntervals.append(intervals[i])
            i= i + 1
        
        while i < n and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(intervals[i][0],newInterval[0])
            newInterval[1] = max(intervals[i][1],newInterval[1])
            i = i + 1
        
        finalIntervals.append(newInterval)

        while i < n:
            finalIntervals.append(intervals[i])
            i = i + 1
        
        return finalIntervals

        