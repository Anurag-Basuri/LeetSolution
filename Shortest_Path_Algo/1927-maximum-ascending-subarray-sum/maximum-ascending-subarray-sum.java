class Solution {
    public int maxAscendingSum(int[] nums) {
        int max_sum = nums[0];
        int cur_sum = nums[0];

        for(int i = 1; i < nums.length; i++){
            if(nums[i] > nums[i - 1]){
                cur_sum += nums[i];
                max_sum = Math.max(max_sum, cur_sum);
            }
            else cur_sum = nums[i];
        }

        return max_sum;
    }
}