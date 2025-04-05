class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        nums.sort()
        i, j = 0, len(nums) - 1
        count = 0

        while i < j:
            s = nums[i] + nums[j]

            if s == k:
                count += 1
                i += 1
                j -= 1
            elif s < k:
                i += 1
            else:
                j -= 1

        return count
