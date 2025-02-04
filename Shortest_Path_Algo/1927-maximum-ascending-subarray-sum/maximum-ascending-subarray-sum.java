class Solution {
    public int maxAscendingSum(int[] nums) {
        int max_sum = 0;
        int cur_sum = nums[0];

        for(int i = 1; i < nums.length; i++){
                max_sum = Math.max(max_sum, cur_sum);
            if(nums[i] > nums[i - 1]){
                cur_sum += nums[i];
            }
            else cur_sum = nums[i];
        }

        max_sum = Math.max(max_sum, cur_sum);

        return max_sum;
    }
}