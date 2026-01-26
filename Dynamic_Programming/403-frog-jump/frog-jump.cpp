class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;

        unordered_map<int, unordered_set<int>> dp;
        unordered_map<int, int> indices;
        
        dp[1].insert(1);
        int n = stones.size();

        for(int i = 0; i < n; i++) indices[stones[i]] = i;

        for(int i = 0; i < n; i++) {
            for(auto jump:dp[i]) {
                for(int next = jump - 1; next < jump + 2; next++) {
                    int nextJump = next + stones[i];
                    dp[indices[nextJump]].insert(next);
                }
            }
        }

        return !dp[n-1].empty();
    }
};