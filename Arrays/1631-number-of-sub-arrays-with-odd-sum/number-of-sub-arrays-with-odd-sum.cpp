class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int evenCount = 1;
        int oddCount = 0;
        int prefixSum = 0;
        int count = 0;
        int MOD = 1e9 + 7;

        for(int num:arr){
            prefixSum += num;

            if(prefixSum % 2 == 0){
                count += oddCount;
                evenCount++;
            }
            else{
                count += evenCount;
                oddCount++;
            }

            count %= MOD;
        }

        return count;
    }
};