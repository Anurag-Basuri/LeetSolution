class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> res(30);

        for(int i:candidates){
            for(int j = 0; j < 30; j++){
                if(i & (1 << j))
                    res[j]++;
            }
        }

        int maxCount = 0;
        for(int count : res) {
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};