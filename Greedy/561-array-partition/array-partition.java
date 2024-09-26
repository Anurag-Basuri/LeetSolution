class Solution {
    public int arrayPairSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        int sum = 0;
        for(int i = 0; i < n; i += 2){
            sum += Math.min(nums[i], nums[i+1]);
        }

        return sum;
    }
}