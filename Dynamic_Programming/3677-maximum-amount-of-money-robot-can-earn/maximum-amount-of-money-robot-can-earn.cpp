class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> memo;

    int recur(int i, int j, vector<vector<int>>& coins, int k) {
        if (i >= n || j >= m)
            return INT_MIN;

        if (i == n - 1 && j == m - 1) {
            if (k > 0)
                return max(0, coins[i][j]);
            return coins[i][j];
        }

        if (memo[i][j][k] != INT_MIN)
            return memo[i][j][k];

        int take = coins[i][j] +
                   max(recur(i + 1, j, coins, k), recur(i, j + 1, coins, k));

        int skip = INT_MIN;
        if (k > 0) {
            skip = max(recur(i + 1, j, coins, k - 1),
                       recur(i, j + 1, coins, k - 1));
        }

        return memo[i][j][k] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();

        int k = 2;

        memo = vector<vector<vector<int>>>(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));

        return recur(0, 0, coins, k);
    }
};