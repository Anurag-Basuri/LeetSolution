class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums) - 1
        l = 0
        r = 0
        jump = 0

        while r < n:
            jr = r
            for i in range(l, r + 1):
                jr = max(jr, i + nums[i])
            l = r + 1
            r = jr
            jump += 1
        
        return jump