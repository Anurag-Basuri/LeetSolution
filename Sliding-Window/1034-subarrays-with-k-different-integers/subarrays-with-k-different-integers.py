class Solution:
    def less_k(self, nums, k):
        n = len(nums)
        l, r, count = 0, 0, 0
        seen = defaultdict(int)

        while r < n:
            seen[nums[r]] += 1

            while len(seen) > k:
                seen[nums[l]] -= 1
                if seen[nums[l]] == 0:
                    del seen[nums[l]]
                l += 1

            count += r - l + 1
            r += 1

        return count
    
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.less_k(nums, k) - self.less_k(nums, k-1)