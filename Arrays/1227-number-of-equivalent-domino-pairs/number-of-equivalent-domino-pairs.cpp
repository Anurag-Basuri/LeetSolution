class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        int count = 0;

        for(auto domino:dominoes) {
            int a = domino[0], b = domino[1];
            int encode = min(a, b) * 10 + max(a, b);

            count += map[encode];
            map[encode]++;
        }

        return count;
    }
};