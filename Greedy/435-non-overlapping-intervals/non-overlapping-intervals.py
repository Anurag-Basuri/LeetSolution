class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda a:a[1])

        count = 0
        end = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] >= end:
                end = intervals[i][1]
            else:
                count += 1
        
        return count