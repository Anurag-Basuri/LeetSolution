class Solution {
public:
    int findComplement(int num) {
        if(num == 0) return 1;

        int mask = num, ans =  num;

        while(num != 0){
            num >>= 1;
            mask |= num;
        }

        return ans ^ mask;
    }
};