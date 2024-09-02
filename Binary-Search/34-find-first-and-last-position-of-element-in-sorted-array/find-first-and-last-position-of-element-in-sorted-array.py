class Solution:
    def binSearch(self, nums, target, lor):
        left, right = 0, len(nums) - 1
        ans = -1
        
        while left <= right:
            mid = left + (right - left) // 2
            
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                ans = mid
                if lor == 1:
                    right = mid - 1
                else:
                    left = mid + 1
        return ans

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        ans = [-1, -1]
        
        ans[0] = self.binSearch(nums, target, 1)
        if ans[0] != -1:
            ans[1] = self.binSearch(nums, target, 0)
        
        return ans