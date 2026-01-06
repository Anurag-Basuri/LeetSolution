class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        
        product = 1
        ans = 0
        j = 0

        for i in range(len(nums)):
            product *= nums[i]

            while product >= k:
                product //= nums[j]
                j += 1

            ans += i - j + 1

        return ans