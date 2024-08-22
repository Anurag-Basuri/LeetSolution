class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),j = 1;

        if(n <= 2) return n;

        for(int i = 2; i < n; i++){
            if (nums[i] != nums[j - 1]) {
                j++;
                nums[j] = nums[i];
            }
        }

        return j+1;
    }
};