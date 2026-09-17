class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = nums1[0];
        bool isOdd = false;

        for(int i:nums1) {
            if(min > i) min = i;

            if(i & 1) isOdd = true;
        }

        if(min & 1) return true;

        return !isOdd;
    }
};