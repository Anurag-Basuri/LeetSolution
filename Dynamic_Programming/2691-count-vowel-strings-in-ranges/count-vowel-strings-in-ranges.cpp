class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        int n = words.size();
        int m = queries.size();
        vector<int> nums(n, 0);
        int c = 0;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            int x = word.size();

            if (vowels.count(word[0]) && vowels.count(word[x - 1]))
                c++;

            nums[i] = c;
        }

        vector<int> ans;

        for (auto query : queries) {
            int l = query[0];
            int r = query[1];

            if (l == 0)
                ans.push_back(nums[r]);
            else
                ans.push_back(nums[r] - nums[l - 1]);
        }

        return ans;
    }
};