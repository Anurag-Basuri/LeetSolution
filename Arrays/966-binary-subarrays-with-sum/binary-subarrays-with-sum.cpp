class Solution {
public:
    int countgoal(vector<int>& nums, int goal){
        int n = nums.size(), ans = 0, sum = 0;
        int left = 0, right = 0;
        
        while(right < n){
            sum += nums[right];

            while(sum > goal && left <= right){
                sum -= nums[left];
                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int x = countgoal(nums, goal);
        int y = countgoal(nums, goal - 1);
        
        return x - y;
    }
};