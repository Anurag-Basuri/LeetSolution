class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        cur = 0

        # Count initial 'W's in the first window of size k
        for i in range(k):
            if blocks[i] == 'W':
                cur += 1

        minCount = cur
        start = 0

        # Sliding window technique
        for i in range(k, len(blocks)):
            if blocks[i] == 'W':
                cur += 1
            if blocks[start] == 'W':
                cur -= 1
            start += 1

            minCount = min(minCount, cur)

        return minCount
