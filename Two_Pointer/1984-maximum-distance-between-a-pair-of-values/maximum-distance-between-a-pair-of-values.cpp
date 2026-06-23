class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        int maxDist = 0;

        while(i < n && j < m) {
            while(j < m && nums1[i] <= nums2[j]) j++;

            maxDist = max(maxDist, j - i - 1);

            i++;
        }

        return maxDist;
    }
};