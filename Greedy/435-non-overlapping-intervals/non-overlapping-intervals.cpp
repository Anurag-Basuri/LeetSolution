class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals by their end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int end = intervals[0][1]; // Initialize end time of the first interval

        // Iterate through the rest of the intervals
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1]; // Update the end time
            } else {
                count++; // Increment the count when an overlap is found
            }
        }

        return count;
    }
};
