class Solution:
    def countAtMostK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l = 0
        r = 0
        ans = 0
        odd_count = 0

        while r < n:
            # Increment odd_count when an odd number is found
            odd_count += nums[r] % 2

            # If odd_count exceeds k, shrink the window from the left
            while odd_count > k:
                odd_count -= nums[l] % 2
                l += 1

            # Count all subarrays ending at r with at most k odd numbers
            ans += (r - l + 1)
            r += 1
        
        return ans
    
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        # Subarrays with exactly k odd numbers
        return self.countAtMostK(nums, k) - self.countAtMostK(nums, k - 1)
