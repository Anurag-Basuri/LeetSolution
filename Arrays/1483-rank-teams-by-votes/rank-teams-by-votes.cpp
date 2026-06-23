class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        int m = votes[0].size();

        vector<vector<int>> freq(26, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) freq[votes[i][j] - 'A'][j]++;
        }

        string result = votes[0];
        sort(result.begin(), result.end(), [&](char a, char b) {
            for(int i = 0; i < m; i++) {
                if(freq[a - 'A'][i] != freq[b - 'A'][i])
                    return freq[a - 'A'][i] > freq[b - 'A'][i];
            }

            return a < b;
        });

        return result;
    }
};