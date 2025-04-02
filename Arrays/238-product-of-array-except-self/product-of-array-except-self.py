class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prod = [1] * n
        cur = 1

        # Compute prefix products
        for i in range(n):
            prod[i] = cur
            cur *= nums[i]

        cur = 1
        # Compute suffix products and multiply with prefix products
        for i in range(n - 1, -1, -1):
            prod[i] *= cur
            cur *= nums[i]

        return prod