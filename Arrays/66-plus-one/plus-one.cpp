class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;

        while(digits[i] == 9) {
            if(i == 0) break;

            digits[i] = 0;
            i--;
        }

        if(digits[i] == 9){
            digits[i] = 1;
            digits.push_back(0);
        } else
            digits[i] = digits[i] + 1;
        
        return digits;
    }
};