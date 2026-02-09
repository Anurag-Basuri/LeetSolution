class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int total_sum = 0;
        for(auto num: nums) {
            total_sum += num;
        }
        vector<vector<int>> first(n+1), second(n+1);
        for(int i=0;i<=(1 << n);i++) {
            int f = 0, s = 0, siz = 0;
            for(int j=0;j<n;j++) {
                if(i & (1 << j)) {
                    siz++;
                    f += nums[j];
                    s += nums[j+n];
                }
            }
            first[siz].push_back(f);
            second[siz].push_back(s);
        }

        for(int i=0;i<=n;i++) sort(second[i].begin(), second[i].end());

        int ans = INT_MAX;
        
        for(int i=0;i<=n;i++) {
            for(auto curr: first[i]) {
                int target = total_sum / 2 - curr;
                int j = n - i;
                int lo = 0, hi = second[j].size() - 1, mid, ind = -1;
                while(lo <= hi) {
                    mid = lo + (hi - lo) / 2;
                    ind = mid;
                    if(second[j][mid] < target) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                if(lo < second[j].size()) {
                    ans = min(ans, abs(total_sum - 2 * (curr + second[j][lo])));
                }
                if(hi >= 0) {
                    ans = min(ans, abs(total_sum - 2 * (curr + second[j][hi])));
                }
            }
        }


        return ans;
    }
};