class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        
        # Edge cases: only one element, or the single element is at the start or end
        if n == 1:
            return nums[0]
        if nums[0] != nums[1]:
            return nums[0]
        if nums[n - 1] != nums[n - 2]:
            return nums[n - 1]
        
        left = 1
        right = n - 2

        while left <= right:
            mid = left + (right - left) // 2

            # Check if the middle element is the single one
            if nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1]:
                return nums[mid]
            
            # Check the pattern based on index parity and adjust the search range
            if (mid % 2 == 1 and nums[mid] == nums[mid - 1]) or (mid % 2 == 0 and nums[mid] == nums[mid + 1]):
                left = mid + 1
            else:
                right = mid - 1
        
        # If not found in the loop, return the left pointer as the result
        return nums[left]
