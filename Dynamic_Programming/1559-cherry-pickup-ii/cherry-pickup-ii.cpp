class Solution {
public:
    int f(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        // Out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        // Last row processed
        if (i == n)
            return 0;

        // Memo check
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int ans = -1e9;

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {

                int val;
                if (j1 == j2)
                    val = grid[i][j1];
                else
                    val = grid[i][j1] + grid[i][j2];

                int next = f(i + 1, j1 + x, j2 + y, n, m, grid, dp);

                ans = max(ans, val + next);
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1))
        );

        // Robot 1 starts at (0, 0), Robot 2 at (0, m-1)
        return f(0, 0, m - 1, n, m, grid, dp);
    }
};