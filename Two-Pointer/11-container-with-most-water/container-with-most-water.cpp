class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int maxarea = 0;

        while(i < j){
            int l = j - i;
            int area = min(heights[i], heights[j]) * l;
            maxarea = (area > maxarea)? area : maxarea;

            if(heights[i] > heights[j]) j--;
            else i++;
        }

        return maxarea;
    }
};