class Solution:
    def findLengthOfLCIS(self, nums: list[int]) -> int:
        if not nums:  # Handle the edge case where the input list is empty
            return 0

        count = 1  # Maximum length of LCIS found so far
        cur = 1    # Current length of the increasing subsequence

        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                cur += 1  # Continue the current sequence
            else:
                cur = 1   # Reset cur for the next sequence

            count = max(count, cur)  # Update the maximum sequence length

        return count
