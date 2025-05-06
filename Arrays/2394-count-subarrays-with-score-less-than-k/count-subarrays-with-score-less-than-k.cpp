class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int i = 0, j = 0;
        int n = nums.size();
        long long count = 0;
        int l = 0;

        for(i = 0; i < n; i++){
            sum += nums[i];

            while(sum * (i - j + 1) >= k){
                sum -= nums[j];
                j++;
            }
            
            count += i -  j + 1;
        }

        return count;
    }
};