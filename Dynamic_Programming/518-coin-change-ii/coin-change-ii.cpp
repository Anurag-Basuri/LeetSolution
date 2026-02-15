class Solution {
public:
    int recur(int i, vector<int> &coins, vector<vector<int>> &dp, int amt) {
        if(amt == 0) return 1;

        if(i == 0) return 0;

        if(dp[i][amt] != -1) return dp[i][amt];

        int notTake = recur(i - 1, coins, dp, amt);

        int take = 0;
        if(amt >= coins[i - 1])
            take = recur(i, coins, dp, amt - coins[i - 1]);

        return dp[i][amt] = take + notTake; 
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        return recur(n, coins, dp, amount);
    }
};