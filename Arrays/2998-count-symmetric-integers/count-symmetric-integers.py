class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        for num in range(low, high + 1):
            s = str(num)
            if len(s) % 2 != 0:
                continue
            half = len(s) // 2
            if sum(map(int, s[:half])) == sum(map(int, s[half:])):
                count += 1
        return count
