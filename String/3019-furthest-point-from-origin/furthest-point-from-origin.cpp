class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int RC = 0;
        int LC = 0;
        int UC = 0;

        for(auto s:moves) {
            if(s == 'L') LC++;
            else if(s == 'R') RC++;
            else UC++;
        }

        return abs(LC - RC) + UC;
    }
};