class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(), sum = 0, minlen = INT_MAX;

        while(i < n && j < n){
            if(sum < target){
                sum += nums[i];
                i++;
            }
            else{
                minlen = min(minlen, i - j);
                sum -= nums[j];
                j++;
            }
        }
        while(sum >= target) {
            minlen = min(minlen, i - j);
            sum -= nums[j++];
        }

        while(sum >= target) {
            minlen = min(minlen, i - j);
            sum -= nums[j++];
        }

        return minlen == INT_MAX ? 0 : minlen;
    }
};