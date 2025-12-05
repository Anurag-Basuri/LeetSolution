class Solution {
public:
    int numSub(string s) {
        long long total_subs = 0;
        long long t1s = 0;
        const long long MOD = 1e9 + 7;

        for(char ch : s) {
            if(ch == '1') {
                t1s++;
            } else {
                total_subs = (total_subs + (t1s * (t1s + 1) / 2) % MOD) % MOD;
                t1s = 0;
            }
        }

        total_subs = (total_subs + (t1s * (t1s + 1) / 2) % MOD) % MOD;

        return total_subs;
    }
};
