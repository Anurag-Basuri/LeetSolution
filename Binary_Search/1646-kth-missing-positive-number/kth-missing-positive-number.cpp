class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            int missing = nums[mid] - mid - 1;

            if(missing >= k) right = mid - 1;
            else left = mid + 1;

            cout << right << " " << left;
        }

        return left + k;
    }
};