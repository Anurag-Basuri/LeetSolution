class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        i = 0
        j = k - 1
        ans = []

        while j < n:
            sort = True
            for l in range(i, j):
                if (nums[l + 1] - nums[l]) != 1:
                    sort = False
                    break
                
            if sort:
                ans.append(nums[j])
            else:
                ans.append(-1)
                
            i += 1
            j += 1

        return ans
