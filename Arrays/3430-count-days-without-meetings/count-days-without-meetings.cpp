class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int sum = 0;
        int last_end = 0;

        for(auto meeting:meetings){
            if(meeting[0] > last_end) sum += meeting[0] - last_end - 1;

            last_end = max(last_end, meeting[1]);
        }

        sum += days - last_end;

        return sum;
    }
};