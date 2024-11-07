class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        res = [0] * 30

        for i in candidates:
            for j in range(30):
                if i & (1 << j):
                    res[j] += 1

        max_count = max(res)
        return max_count
