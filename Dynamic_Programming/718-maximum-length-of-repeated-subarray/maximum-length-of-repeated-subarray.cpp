class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> common(n + 1, vector<int>(m + 1, 0));
        
        // Variable to track the maximum length found ANYWHERE in the grid
        int ans = 0; 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums1[i - 1] == nums2[j - 1]) {
                    common[i][j] = 1 + common[i - 1][j - 1];
                    
                    ans = max(ans, common[i][j]);
                }
                else {
                    common[i][j] = 0;
                }
            }
        }

        return ans;
    }
};