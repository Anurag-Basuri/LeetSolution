class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int sum = 0, count = 0;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                count++;
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
            sum += nums[i];
        }

        if ((sum + nums[n - 1] + nums[n - 2]) == n) return count;

        return -1;
    }
}
