class Solution:
    def dfs(self, vis, grid, sr, sc, n, m):
        if sr < 0 or sr >= n or sc < 0 or sc >= m or vis[sr][sc] != 0 or grid[sr][sc] == 0:
            return

        vis[sr][sc] = 1

        self.dfs(vis, grid, sr - 1, sc, n, m)
        self.dfs(vis, grid, sr + 1, sc, n, m)
        self.dfs(vis, grid, sr, sc - 1, n, m)
        self.dfs(vis, grid, sr, sc + 1, n, m)

    def numEnclaves(self, grid):
        n = len(grid)
        m = len(grid[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]

        # Mark boundary-connected land cells
        for i in range(m):
            if grid[0][i] == 1:
                self.dfs(vis, grid, 0, i, n, m)
            if grid[n - 1][i] == 1:
                self.dfs(vis, grid, n - 1, i, n, m)

        for i in range(n):
            if grid[i][0] == 1:
                self.dfs(vis, grid, i, 0, n, m)
            if grid[i][m - 1] == 1:
                self.dfs(vis, grid, i, m - 1, n, m)

        # Count remaining land cells not visited
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and vis[i][j] == 0:
                    ans += 1

        return ans
