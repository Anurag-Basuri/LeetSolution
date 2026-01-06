class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i = 0
        j = 0
        n = len(nums)
        sum = 0
        minlen = float(inf)

        while i < n and j < n:
            if sum < target:
                sum += nums[i]
                i += 1
            else:
                minlen = min(minlen, i - j)
                sum -= nums[j]
                j += 1
        
        while sum >= target :
            minlen = min(minlen, i - j)
            sum -= nums[j]
            j += 1

        return minlen if minlen != float(inf) else 0
    