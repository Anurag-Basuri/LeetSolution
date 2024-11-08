class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer;
        int XOR = 0;
        for(int i:nums) XOR ^= i;

        int mask = (1 << maximumBit) - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            answer.push_back(XOR ^ mask);
            XOR ^= nums[i];
        }

        return answer;
    }
};