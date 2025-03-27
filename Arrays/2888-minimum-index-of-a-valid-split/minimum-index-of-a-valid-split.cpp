class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> count;

        for(int i = 0; i < n; i++) count[nums[i]]++;

        int freq = 0, mostfreq;
        for(auto it:count){
            if(freq < it.second){
                freq = it.second;
                mostfreq = it.first;
            }
        }

        int c = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == mostfreq) c++;
            int c1 = freq - c;

            if((c*2 > i+1) && (c1*2 > n-i-1)) return i;
        }

        return -1;
    }
};