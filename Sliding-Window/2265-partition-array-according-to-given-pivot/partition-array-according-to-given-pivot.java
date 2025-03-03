import java.util.*;

class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> lesser = new ArrayList<>();
        List<Integer> equal = new ArrayList<>();
        List<Integer> greater = new ArrayList<>();

        for (int num : nums) {
            if (num < pivot) lesser.add(num);
            else if (num == pivot) equal.add(num);
            else greater.add(num);
        }

        // Merge all lists
        lesser.addAll(equal);
        lesser.addAll(greater);

        // Convert List to Array
        int[] result = new int[nums.length];
        for (int i = 0; i < lesser.size(); i++) {
            result[i] = lesser.get(i);
        }

        return result;
    }
}
