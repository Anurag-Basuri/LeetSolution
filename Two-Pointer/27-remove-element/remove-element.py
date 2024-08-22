class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0;
        for i in range(0, len(nums)):
            nums[j] = nums[i]
            if(nums[i] != val):
                j += 1
        return j