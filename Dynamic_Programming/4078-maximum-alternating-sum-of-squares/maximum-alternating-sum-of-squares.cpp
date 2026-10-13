class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        long long sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(i < n/2) sum -= pow(nums[i], 2);
            else sum += pow(nums[i], 2);
        }

        return sum;
    }
};