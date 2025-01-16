class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        if (n1 % 2 != 0) {
            for (int num : nums2)
                result ^= num;
        }

        if (n2 % 2 != 0) {
            for (int num : nums1)
                result ^= num;
        }

        return result;
    }
};
