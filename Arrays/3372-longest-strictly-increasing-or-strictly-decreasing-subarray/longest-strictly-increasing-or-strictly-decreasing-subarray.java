class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int increasing = 0;
        int decreasing = 0;
        int l = nums.length, inc = 1, dec = 1;

        for(int i = 1; i < l; i++){
            if(nums[i - 1] < nums[i]){
                inc++;
                increasing = Math.max(increasing, inc);
            }
            else inc = 1;

            if(nums[i - 1] > nums[i]){
                dec++;
                decreasing = Math.max(decreasing, dec);
            }
            else dec = 1;
        }

        increasing = Math.max(increasing, inc);
        decreasing = Math.max(decreasing, dec);

        return Math.max(decreasing, increasing);
    }
}