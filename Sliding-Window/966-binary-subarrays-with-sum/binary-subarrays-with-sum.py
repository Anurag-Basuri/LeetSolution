class Solution:
    def countgoal(self, nums, goal):
        n = len(nums)
        ans = 0
        sum_val = 0
        left = 0
        
        for right in range(n):
            sum_val += nums[right]
            
            # Adjust the window if sum exceeds goal
            while sum_val > goal and left <= right:
                sum_val -= nums[left]
                left += 1
            
            # Count all subarrays ending at `right` that have sum <= goal
            ans += right - left + 1
            
        return ans
    
    def numSubarraysWithSum(self, nums, goal):
        x = self.countgoal(nums, goal)
        y = self.countgoal(nums, goal - 1)
        
        return x - y
