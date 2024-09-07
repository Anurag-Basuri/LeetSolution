class Solution:
    def findKthPositive(self, nums: List[int], k: int) -> int:
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = left + (right - left) // 2
            missing = nums[mid] - mid - 1
            
            if missing >= k:
                right = mid - 1
            else:
                left = mid + 1

            print(right, left)
        
        return left + k
