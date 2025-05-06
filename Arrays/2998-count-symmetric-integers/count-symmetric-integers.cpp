class Solution {
public:
    bool check(int num, int l){
        int sum1 = 0, sum2 = 0;

        for(int i = 0; i < l; i++){
            if(i < l/2) sum1 += num % 10;
            else sum2 += num % 10;

            num /= 10;
        }
        cout << sum1 << sum2 << "\n";

        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for(int i = low; i <= high; i++){
            int l = floor(log10(i)) + 1;

            if(l%2 != 0) continue;
            
            if(check(i, l) == true)
                count++;
        }

        return count;
    }
};