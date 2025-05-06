class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        total_sum = 0

        for i in range(n - 2):
            if nums[i] == 0:
                count += 1
                nums[i] ^= 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1

            total_sum += nums[i]

        if (total_sum + nums[n - 1] + nums[n - 2]) == n:
            return count

        return -1
        