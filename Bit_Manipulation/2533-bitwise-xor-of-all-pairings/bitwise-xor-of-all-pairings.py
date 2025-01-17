class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        xor = 0
        n1, n2 = len(nums1), len(nums2)

        if n1 % 2 != 0:
            for num in nums2:
                xor ^= num

        if n2 % 2 != 0:
            for num in nums1:
                xor ^= num

        return xor
