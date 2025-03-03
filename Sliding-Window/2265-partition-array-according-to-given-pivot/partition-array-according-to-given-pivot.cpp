class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less = 0, equal = 0;

        for(int i:nums){
            if(i == pivot) equal++;
            else if(i < pivot) less++;
        }

        int start = 0;
        int last = less + equal;
        vector<int> ans(nums.size(), pivot);
        
        for(int i:nums){
            if(i < pivot){
                ans[start] = i;
                start++;
            }
            else if(i > pivot){
                ans[last] = i;
                last++;
            }
        }

        return ans;
    }
};