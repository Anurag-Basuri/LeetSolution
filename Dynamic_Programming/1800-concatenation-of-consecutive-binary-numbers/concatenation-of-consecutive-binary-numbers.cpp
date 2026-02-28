class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        int bits = 0;

        for (int i = 1; i <= n; i++) {
            // if i is power of 2, increase bit length
            if ((i & (i - 1)) == 0) {
                bits++;
            }

            res = ((res << bits) % MOD + i) % MOD;
        }

        return res;
    }
};