class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser;
        vector<int> equal;
        vector<int> greater;

        for(int i:nums){
            if(i < pivot) lesser.push_back(i);
            else if(i == pivot) equal.push_back(i);
            else greater.push_back(i);
        }

        lesser.insert(lesser.end(), equal.begin(), equal.end());
        lesser.insert(lesser.end(), greater.begin(), greater.end());
        return lesser;
    }
};