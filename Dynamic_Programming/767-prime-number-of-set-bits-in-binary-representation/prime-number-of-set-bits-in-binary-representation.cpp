class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        
        // Bitmask representing primes < 20: 
        // Bits 2, 3, 5, 7, 11, 13, 17, 19 are set to 1.
        // binary: 10100010100010101100
        // decimal: 665772
        const int primeMask = 665772; 
        
        for (int i = left; i <= right; ++i) {
            // __builtin_popcount is an intrinsic C++ function 
            // that returns the number of set bits (1s)
            int setBits = __builtin_popcount(i);
            
            // Check if the number of set bits is a prime using the mask
            if ((primeMask >> setBits) & 1) {
                count++;
            }
        }
        
        return count;
    }
};