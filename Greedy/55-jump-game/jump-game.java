class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int maxp = 0;

        for (int i = 0; i < n; i++) {
            if (i > maxp) return false;
            maxp = Math.max(i + nums[i], maxp);
            if (maxp >= n - 1) return true;
        }

        return true;
    }
}
