class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        int reachable = 0;
        for (int i = 1; i < n; i++) {
            if (i - minJump >= 0)
                reachable += dp[i - minJump];

            if (i - maxJump - 1 >= 0)
                reachable -= dp[i - maxJump - 1];

            if (s[i] == '0' && reachable > 0)
                dp[i] = 1;
        }

        return dp[n - 1];
    }
};