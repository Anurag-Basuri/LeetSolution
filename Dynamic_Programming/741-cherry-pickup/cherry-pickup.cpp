class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<int>>> dp(
            2*n - 1,
            vector<vector<int>>(n, vector<int>(n, -1e9))
        );

        dp[0][0][0] = grid[0][0];

        for(int k = 1; k < 2*n - 1; k++) {

            for(int i1 = max(0, k - (n - 1));
                i1 <= min(n - 1, k); i1++) {

                for(int i2 = max(0, k - (n - 1));
                    i2 <= min(n - 1, k); i2++) {

                    int j1 = k - i1;
                    int j2 = k - i2;

                    if(j1 >= n || j2 >= n) continue;
                    if(grid[i1][j1] == -1 || grid[i2][j2] == -1)
                        continue;

                    int best = -1e9;

                    for(int p1 = i1; p1 >= i1 - 1; p1--) {
                        for(int p2 = i2; p2 >= i2 - 1; p2--) {

                            if(p1 >= 0 && p2 >= 0)
                                best = max(best, dp[k-1][p1][p2]);
                        }
                    }

                    if(best < 0) continue;

                    int cherries = (i1 == i2)
                        ? grid[i1][j1]
                        : grid[i1][j1] + grid[i2][j2];

                    dp[k][i1][i2] = best + cherries;
                }
            }
        }

        return max(0, dp[2*n - 2][n-1][n-1]);
    }
};