class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });

        int totalUnits = 0, size = 0, i = 0;

        for(int i = 0; i < boxTypes.size() && size < truckSize; i++){
            if(size + boxTypes[i][0] > truckSize){
                totalUnits += boxTypes[i][1] * (truckSize - size);
                break; 
            }
            else{
                totalUnits += boxTypes[i][0] * boxTypes[i][1];
                size += boxTypes[i][0];
            }
        }

        return totalUnits;
    }
};