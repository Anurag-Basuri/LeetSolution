class Solution:
    def dfs(self, matrix, memory, i, j, directions) -> int:
        if memory[i][j] != -1:
            return memory[i][j]

        max_path = 1

        for dx, dy in directions:
            x, y = i + dx, j + dy
            if (
                0 <= x < len(matrix)
                and 0 <= y < len(matrix[0])
                and matrix[x][y] > matrix[i][j]
            ):
                max_path = max(max_path, 1 + self.dfs(matrix, memory, x, y, directions))

        memory[i][j] = max_path
        return max_path

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        memory = [[-1] * n for _ in range(m)]
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        ans = 0

        for i in range(m):
            for j in range(n):
                ans = max(ans, self.dfs(matrix, memory, i, j, directions))

        return ans
