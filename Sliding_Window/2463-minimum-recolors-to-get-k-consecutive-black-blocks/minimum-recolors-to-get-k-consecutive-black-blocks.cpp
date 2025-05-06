class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cur = 0;

        for(int i = 0; i < k; i++)
            if(blocks[i] == 'W') cur++;
        cout << cur;

        int minCount = cur, start = 0;
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i] == 'W') cur++;
            if(blocks[start] == 'W') cur--;
            start++;

            minCount = min(minCount, cur);
        }

        return minCount;
    }
};