class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;

        for(int i:nums) {
            int sum = 0;
            int count = 0;

            for(int j = 1; j <= sqrt(i); j++) {
                if(i % j == 0)
                {
                    int d1 = j;
                    int d2 = i / j;

                    if(d1 == d2)
                    {
                        count += 1;
                        sum += d1;
                    }
                    else
                    {
                        count += 2;
                        sum += d1 + d2;
                    }

                    if(count > 4)
                        break;
                }
            }

            if(count == 4) total_sum += sum;
        }

        return total_sum;
    }
};