class Solution {
    public int jump(int[] nums) {
        int n = nums.length - 1;
        int l = 0;
        int r = 0;
        int jumps = 0;

        while (r < n) {
            int jr = r;
            for (int i = l; i <= r; i++) {
                jr = Math.max(jr, i + nums[i]);
            }
            l = r + 1;
            r = jr;
            jumps++;
        }

        return jumps;
    }
}
