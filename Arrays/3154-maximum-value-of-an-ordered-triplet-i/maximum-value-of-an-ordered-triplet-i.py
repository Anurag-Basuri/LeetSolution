class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        max_i = nums[0]
        i_minus_j = -int(1e9)
        max_sum = 0

        for i in range(len(nums) - 1):
            i_minus_j = max(i_minus_j, max_i - nums[i])
            max_i = max(max_i, nums[i])
            max_sum = max(max_sum, i_minus_j * nums[i + 1])

        return max_sum