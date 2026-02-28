class Solution {
public:
    int f(int i1, int j1, int i2, vector<vector<int>>& grid,
          vector<vector<vector<int>>> &dp, int n) {
        int j2 = i1 + j1 - i2;

        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n)
            return -1e9;

        if (grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e9;

        if (i1 == n - 1 && j1 == n - 1)
            return grid[i1][j1];

        if (dp[i1][j1][i2] != -1)
            return dp[i1][j1][i2];

        int cherries =
            (i1 == i2 && j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];

        int best = max({f(i1 + 1, j1, i2 + 1, grid, dp, n),
                        f(i1 + 1, j1, i2, grid, dp, n),
                        f(i1, j1 + 1, i2 + 1, grid, dp, n),
                        f(i1, j1 + 1, i2, grid, dp, n)});

        return dp[i1][j1][i2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans = f(0, 0, 0, grid, dp, n);

        return max(0, ans);
    }
};