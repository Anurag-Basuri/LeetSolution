class Solution:
    def helper(self, nums, n, x):
        count = defaultdict(int)

        for num in nums:
            count[num] += 1

        arr = [(key, value) for key, value in count.items()]
        arr.sort(key=lambda a: (a[1], a[0]), reverse=True)

        total = 0
        for i in range(min(len(arr), x)):
            total += arr[i][1] * arr[i][0]
        
        return total

    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        ans = []
        l = len(nums)

        for i in range(l - k + 1):
            ans.append(self.helper(nums[i:i+k], k, x))
        
        return ans
        