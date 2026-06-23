class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        
        long long totalSum = 0;
        for(int i:beans) totalSum += i;

        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            long long beansRemoved =  totalSum - (long long)(n - i) * beans[i];
            ans = min(ans, beansRemoved);
        }

        return ans;
    }
};