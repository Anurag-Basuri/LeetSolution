class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;

        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target)
                return -1;

            else if (tops[i] != target)
                rotateTop++;
            else if (bottoms[i] != target)
                rotateBottom++;
        }

        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1) return result;

        if (tops[0] != bottoms[0]) {
            result = check(bottoms[0], tops, bottoms);
            return result;
        }

        return -1;
    }
};
