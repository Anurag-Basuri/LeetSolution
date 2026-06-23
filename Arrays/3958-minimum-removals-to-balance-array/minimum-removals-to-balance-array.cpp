class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int minCount = 1e9;
        int n = nums.size();
        int gAns = 1e9;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            long long target = (long long)nums[i] * k;

            int s = i, e = n - 1;
            int ans = 1e9;

            while (s <= e) {
                int mid = (s + e) / 2;

                if (nums[mid] <= target) {
                    // cout << n - 1 - mid + i;
                    ans = min(ans, n - 1 - mid + i);
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            // cout << " ";

            gAns = min(gAns, ans);
        }
        return gAns;
    }
};