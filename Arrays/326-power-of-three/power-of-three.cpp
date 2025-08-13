class Solution {
public:
    bool isPowerOfThree(int n) {
        int rem = 0;
        while (n > 1 && rem == 0) {
            rem = n % 3;
            n /= 3;
        }
        return rem == 0 && n == 1;
    }
};