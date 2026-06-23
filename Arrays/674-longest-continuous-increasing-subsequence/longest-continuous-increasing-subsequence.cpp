class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 0, n = nums.size(), cur = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                cur++;
                cout << 1;
            }    
            else {
                cur = 0;
            }
            count = (cur > count)? cur : count;
        }

        return count + 1;
    }
};