class Solution {
public:
    bool sorted(vector<int>&nums){
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        if(sorted(nums)) return count;
        while(true){
            if(sorted(nums))return count;
            int minSum=INT_MAX;
            int idx=0;
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i]+nums[i+1]<minSum){
                    minSum=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            nums[idx]=minSum;
            nums.erase(nums.begin()+idx+1);
            count++;
        }
        return count;
    }
};