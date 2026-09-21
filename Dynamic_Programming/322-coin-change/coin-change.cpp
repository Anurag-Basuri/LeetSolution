class Solution {
public:
    int recur(int i, vector<int> &coins, int amt, int n, vector<vector<int>> &vis) {
        if(amt <= 0) return 0;

        if(i < 0) return 1e9;

        if(vis[i][amt]) return vis[i][amt];

        int notTake = recur(i - 1, coins, amt, n, vis);

        int take = 1e9;
        if(coins[i] <= amt)
            take = 1 + recur(i, coins, amt - coins[i], n, vis);
        
        return vis[i][amt] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> vis(n, vector<int>(amount + 1, 0));

        int ans = recur(n - 1, coins, amount, n, vis);
        return (ans != 1e9)? ans:-1;
    }
};