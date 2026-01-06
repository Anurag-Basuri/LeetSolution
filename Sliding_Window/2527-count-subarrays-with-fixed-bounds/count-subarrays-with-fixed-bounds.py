class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        n = len(nums)
        count = 0

        leftBound = -1
        lastMin = -1
        lastMax = -1

        for i in range(n):
            if nums[i] < minK or nums[i] > maxK:
                leftBound = i
            if nums[i] == minK:
                lastMin = i
            if nums[i] == maxK:
                lastMax = i

            minIndex = min(lastMin, lastMax)
            if minIndex > leftBound:
                count += minIndex - leftBound

        return count
