class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        map = dict()
        count = 0

        for i in nums:
            x = k - i
            if x in map and map[x] > 0:
                count += 1
                map[x] -= 1
            else:
                map[i] = map.get(i, 0) + 1
        
        return count
