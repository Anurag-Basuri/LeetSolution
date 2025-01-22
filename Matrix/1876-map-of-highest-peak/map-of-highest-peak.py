class Solution:
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        n = len(isWater)
        m = len(isWater[0])
        ans = [[-1] * m for _ in range(n)]
        q = deque()

        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1:
                    q.append((i, j))
                    ans[i][j] = 0

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        while q:
            row, col = q.popleft()

            for dr, dc in directions:
                newRow, newCol = row + dr, col + dc

                if 0 <= newRow < n and 0 <= newCol < m and ans[newRow][newCol] == -1:
                    ans[newRow][newCol] = ans[row][col] + 1
                    q.append((newRow, newCol))

        return ans
