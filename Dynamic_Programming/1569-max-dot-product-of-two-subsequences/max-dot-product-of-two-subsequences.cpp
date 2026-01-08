class Solution {
public:

int f(int i,vector<int>&a,int n,int j,vector<int>&b,int m, vector<vector<int>> &dp){
    if(i==n or j==m){
        return 0;
    }
    if(dp[i][j]!=-1e7){
        return dp[i][j];
    }
    int cur=a[i]*b[j];
    int one = f(i+1,a,n,j,b,m,dp);
    int two= f(i,a,n,j+1,b,m,dp);
    int three=f(i+1,a,n,j+1,b,m,dp);
    return dp[i][j]=max({one,two,cur+three,three});
}
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        int i=0;
        int j=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1e7));
        int ans= f(i,a,n,j,b,m,dp);
        
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                if(ans!=0){
                    return ans;
                }
                return max({a[n-1]*b[0],a[0]*b[m-1]});

        
    }
};