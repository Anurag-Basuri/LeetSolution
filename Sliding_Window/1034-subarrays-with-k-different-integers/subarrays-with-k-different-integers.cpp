class Solution {
public:
    int less_k(vector<int>& nums, int k){
        int n = nums.size(), l = 0, r = 0, count = 0;
        unordered_map<int, int> seen;

        while(r < n){
            seen[nums[r]]++;

            while(seen.size() > k){
                seen[nums[l]]--;
                if(seen[nums[l]] == 0)
                    seen.erase(nums[l]);
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return less_k(nums, k) - less_k(nums, k-1);
    }
};