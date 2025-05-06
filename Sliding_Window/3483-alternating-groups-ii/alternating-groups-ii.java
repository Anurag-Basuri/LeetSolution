class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int count = 0;
        int curLen = 1;
        int prevColor = colors[0];

        // Loop through the array with circular traversal logic
        for (int i = 1; i < n + k - 1; i++) {
            int idx = i % n;  // Circular index calculation

            // If the current color matches the previous one
            if (colors[idx] == prevColor) {
                curLen = 1;   // Reset the alternating sequence length
                prevColor = colors[idx];  // Update the previous color
                continue;
            }

            // Extend the alternating sequence
            curLen++;

            // If alternating sequence reaches at least k, count it
            if (curLen >= k) {
                count++;
            }

            // Update previous color for the next iteration
            prevColor = colors[idx];
        }

        return count;
    }
}
