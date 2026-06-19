class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char task : tasks)
            freq[task - 'A']++;

        sort(freq.begin(), freq.end());
        int maxFreq = freq[25] - 1;
        int idleTime = maxFreq * n;
        
        for(int i = 24; i >= 0 && freq[i] > 0; i--)
            idleTime -= min(freq[i], maxFreq);
        
        return idleTime > 0? idleTime + tasks.size() : tasks.size();
    }
};