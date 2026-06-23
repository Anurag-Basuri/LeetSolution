class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;
        int maxDist = 0;
        int index = 0;
        
        while (n > 0) {
            if (n & 1) {               
                if (lastPos != -1) {
                    maxDist = max(maxDist, index - lastPos);
                }
                lastPos = index;
            }
            n >>= 1;                     
            index++;
        }
        
        return maxDist;
    }
};