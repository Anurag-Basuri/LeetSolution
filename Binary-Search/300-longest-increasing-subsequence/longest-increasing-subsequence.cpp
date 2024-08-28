class Solution {
public:
    int subsequence(int i, vector<int>& nums, unordered_map<int, int>& seen){
        if(i == nums.size()) return 0;

        if(seen.find(i) != seen.end()) return seen[i];

        int maxlen = 1;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] > nums[i])
                maxlen = max(maxlen, 1 + subsequence(j, nums, seen));
        }

        seen[i] = maxlen;
        return maxlen;
    }

    int lengthOfLIS(vector<int>& nums) {
        unordered_map<int, int> seen;
        int maxlen = 0;

        for(int i = 0; i < nums.size(); i++)
            maxlen = max(maxlen, subsequence(i, nums, seen));
        
        return maxlen;
    }
};