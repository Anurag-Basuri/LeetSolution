class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> track;
        
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) track[5]++;
            else if(bills[i] == 10){
                track[10]++;
                if(track[5]) track[5]--;
                else return false;
            }
            else{
                if(track[10] && track[5]){
                    track[10]--;
                    track[5]--;
                }
                else if(track[5] >= 3){
                    track[5] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};