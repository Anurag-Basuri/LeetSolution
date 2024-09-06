class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        low, high = 1, x

        while low <= high:
            mid = low + (high - low) // 2
            sq = mid * mid

            if sq == x:
                return mid
            elif sq > x:
                high = mid - 1
            else:
                low = mid + 1

        return high  # Return the largest integer whose square is <= x
