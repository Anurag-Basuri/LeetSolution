class Solution {
    public int maxPower(String s) {
        int maxLen = 0;
        int n = s.length();

        for (int i = 0; i < n;) {
            char cur = s.charAt(i); // Current character
            int j = i, len = 0;

            // Count consecutive identical characters
            while (j < n && s.charAt(j) == cur) {
                len++;
                j++;
            }

            i = j; // Move 'i' to the next non-matching character
            maxLen = Math.max(maxLen, len);
        }

        return maxLen;
    }
}
