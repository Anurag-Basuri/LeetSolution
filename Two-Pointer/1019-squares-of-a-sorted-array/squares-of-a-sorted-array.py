from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l, r = 0, len(nums) - 1
        ans = []

        while l <= r:
            a = nums[l] ** 2
            b = nums[r] ** 2

            if a > b:
                ans.append(a)
                l += 1
            else:
                ans.append(b)
                r -= 1

        return ans[::-1]
