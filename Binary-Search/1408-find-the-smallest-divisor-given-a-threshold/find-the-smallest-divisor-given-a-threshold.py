
class Solution:
    def threshold(self, nums: List[int], n: int) -> int:
        ans = 0
        for i in nums:
            ans += math.ceil(i / n)
        return ans

    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        left, right = 1, max(nums)
        ans = -1
        
        while left <= right:
            mid = left + (right - left) // 2

            if self.threshold(nums, mid) <= threshold:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return ans
