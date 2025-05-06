class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        noz = 0
        maxl = 0
        low = 0
        high = 0

        while high < n:
            if nums[high] == 0:
                noz += 1

            if noz > k:
                if nums[low] == 0:
                    noz -= 1
                low += 1

            if noz <= k:
                maxl = max(maxl, high - low + 1)

            high += 1

        return maxl
