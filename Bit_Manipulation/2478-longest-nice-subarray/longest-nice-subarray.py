class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        xor_sum = 0
        cur_sum = 0
        i = 0
        max_len = 0

        for j in range(len(nums)):
            xor_sum ^= nums[j]
            cur_sum += nums[j]

            while xor_sum != cur_sum:
                xor_sum ^= nums[i]
                cur_sum -= nums[i]
                i += 1

            max_len = max(max_len, j - i + 1)

        return max_len
