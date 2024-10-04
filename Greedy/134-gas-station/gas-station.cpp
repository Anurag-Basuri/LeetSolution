class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, total = 0, ind = 0;

        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if(sum < 0){
                ind = i + 1;
                sum = 0;
            }
        }

        if(total >= 0) return ind;
        else return -1;
    }
};