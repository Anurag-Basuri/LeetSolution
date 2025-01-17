class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        answer = []
        XOR = 0
        for num in nums:
            XOR ^= num

        mask = (1 << maximumBit) - 1
        for i in range(len(nums) - 1, -1, -1):
            answer.append(XOR ^ mask)
            XOR ^= nums[i]

        return answer
