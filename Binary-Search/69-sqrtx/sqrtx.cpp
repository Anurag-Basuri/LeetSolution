class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;

        int low = 1, high = x;

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long sq = (long long)mid * mid;  // Use long long for safety during multiplication

            if(sq == x) return mid;  // Direct return if exact match
            else if(sq > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return high;  // Return the largest integer whose square is <= x
    }
};
