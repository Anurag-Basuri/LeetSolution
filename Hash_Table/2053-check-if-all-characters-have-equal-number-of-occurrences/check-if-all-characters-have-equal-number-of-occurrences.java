import java.util.*;

class Solution {
    public boolean areOccurrencesEqual(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        
        // Count occurrences of each character
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // Store frequency values in a list
        ArrayList<Integer> arr = new ArrayList<>();
        for (char key : map.keySet()) {
            arr.add(map.get(key));
        }

        // Check if all values in the list are the same
        for (int i = 1; i < arr.size(); i++) {
            if (!arr.get(i - 1).equals(arr.get(i))) { // Use .equals() instead of !=
                return false;
            }
        }
        return true;
    }
}
