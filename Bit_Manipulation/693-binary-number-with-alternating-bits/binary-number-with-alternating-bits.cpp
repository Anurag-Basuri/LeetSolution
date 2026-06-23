class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool isSetBit = false;
        if(n%2)isSetBit=true;
        int MSB = floor(log2(n));
        for(int i = 0; i <= MSB; i++){
            if((n >> i & 1) == isSetBit)isSetBit = !isSetBit;
            else return false;
        }
        return true;
    }
};