class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j1][j2]
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0))
        );

        // Base case: last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Fill from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int ans = -1e9;

                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {

                            int nj1 = j1 + x;
                            int nj2 = j2 + y;

                            if (nj1 < 0 || nj1 >= m || nj2 < 0 || nj2 >= m)
                                continue;

                            int value;
                            if (j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            value += dp[i + 1][nj1][nj2];

                            ans = max(ans, value);
                        }
                    }

                    dp[i][j1][j2] = ans;
                }
            }
        }

        // Start positions
        return dp[0][m - 1][0];
    }
};