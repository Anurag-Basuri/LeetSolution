class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), sum1 = 0, sum2 = 0, count = 0;
        int arr[n];

        for(int i = n-1; i >= 0; i--) {
            sum1 += nums[i];
            arr[i] = sum1;
        }

        for(int i = 1; i < n; i++) {
            sum2 += nums[i-1];

            if ((arr[i] - sum2) % 2 == 0) count++;
        }

        return count;
    }
};