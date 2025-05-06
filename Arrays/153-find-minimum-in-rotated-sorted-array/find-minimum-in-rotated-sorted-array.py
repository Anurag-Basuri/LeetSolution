class Solution:
    def findMin(self, nums: list[int]) -> int:
        ans = float('inf')
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            # If the array is already sorted
            if nums[left] <= nums[right]:
                ans = min(ans, nums[left])
                break

            # If the left part is sorted
            if nums[left] <= nums[mid]:
                ans = min(ans, nums[left])
                left = mid + 1
            # If the right part is sorted
            else:
                ans = min(ans, nums[mid])
                right = mid - 1

        return ans
