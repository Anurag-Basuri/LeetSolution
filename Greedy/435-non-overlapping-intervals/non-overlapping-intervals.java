class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // Sort intervals by their end time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        int count = 0;
        int end = intervals[0][1]; // Initialize end time of the first interval

        // Iterate through the rest of the intervals
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1]; // Update the end time
            } else {
                count++; // Increment the count when an overlap is found
            }
        }

        return count;
    }
}
