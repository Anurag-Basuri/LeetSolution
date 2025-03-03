class Solution:
    def pivotArray(self, nums, pivot):
        less = 0
        equal = 0

        # Count elements less than and equal to pivot
        for num in nums:
            if num == pivot:
                equal += 1
            elif num < pivot:
                less += 1

        start = 0
        last = less + equal
        ans = [pivot] * len(nums)  # Initialize ans array with pivot

        # Distribute elements in ans array
        for num in nums:
            if num < pivot:
                ans[start] = num
                start += 1
            elif num > pivot:
                ans[last] = num
                last += 1

        return ans
