class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;

        int low = 1, high = x;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            long int sq = (long int)mid * mid;

            if(sq == x){
                ans = mid;
                break;
            }
            else if(sq > x)
                high = mid - 1;
            else{
                low = mid + 1;
                ans = mid;
            }
        }

        return ans;
    }
};