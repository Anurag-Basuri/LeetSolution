class Solution {
    private int less_k(int[] nums, int k) {
        int n = nums.length, l = 0, r = 0, count = 0;
        HashMap<Integer, Integer> seen = new HashMap<>();

        while (r < n) {
            seen.put(nums[r], seen.getOrDefault(nums[r], 0) + 1);

            while (seen.size() > k) {
                seen.put(nums[l], seen.get(nums[l]) - 1);
                if (seen.get(nums[l]) == 0)
                    seen.remove(nums[l]);
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        return less_k(nums, k) - less_k(nums, k - 1);
    }
}