class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        # Initialize the spiral matrix with zeros
        spiral = [[0] * n for _ in range(n)]
        num = 1  # Start with 1
        top, bottom, left, right = 0, n - 1, 0, n - 1  # Boundaries

        while top <= bottom and left <= right:
            # Fill top row
            for i in range(left, right + 1):
                spiral[top][i] = num
                num += 1
            top += 1  # Move the top boundary down

            # Fill right column
            for i in range(top, bottom + 1):
                spiral[i][right] = num
                num += 1
            right -= 1  # Move the right boundary left

            # Fill bottom row (if applicable)
            if top <= bottom:
                for i in range(right, left - 1, -1):
                    spiral[bottom][i] = num
                    num += 1
                bottom -= 1  # Move the bottom boundary up

            # Fill left column (if applicable)
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    spiral[i][left] = num
                    num += 1
                left += 1  # Move the left boundary right

        return spiral
