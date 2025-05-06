class Solution {
    public long maximumTripletValue(int[] nums) {
        long max_i = nums[0], i_minus_j = (long) -1e9, max_sum = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            i_minus_j = Math.max(i_minus_j, max_i - nums[i]);
            max_i = Math.max(max_i, (long) nums[i]);
            max_sum = Math.max(max_sum, i_minus_j * nums[i + 1]);
        }

        return max_sum;
    }
}

