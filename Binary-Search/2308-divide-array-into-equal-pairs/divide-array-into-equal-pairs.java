class Solution {
    public boolean divideArray(int[] nums) {
        HashSet<Integer> check = new HashSet<>();

        for (int num : nums) {
            if (check.contains(num)) {
                check.remove(num);
            } else {
                check.add(num);
            }
        }

        return check.isEmpty();
    }
}
