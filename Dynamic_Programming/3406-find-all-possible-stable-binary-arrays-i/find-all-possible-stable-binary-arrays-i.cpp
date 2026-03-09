class Solution {
public:

    typedef long long ll;
    const ll mod=1e9+7;

    ll solve(int zero, int one, bool lastOne, int limit, 
    vector<vector<vector<ll>>>&dp){
        if(zero==0 && one==0){
            return 1;
        }
        if(dp[zero][one][lastOne]!=-1) return dp[zero][one][lastOne];
        ll res=0;
        if(lastOne){
            for(int len=1; len<=min(limit, zero); len++){
                res=(res+solve(zero-len, one, false, limit, dp))%mod;
            }
        }else{
            for(int len=1; len<=min(limit, one); len++){
                res=(res+solve(zero, one-len, true, limit, dp))%mod;
            }
        }
        return dp[zero][one][lastOne]=res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<ll>>>dp(zero+1, vector<vector<ll>>(one+1, 
        vector<ll>(2, -1)));
        return (solve(zero, one, false, limit, dp)+solve(zero, one, true, limit, dp))%mod;        
    }
};