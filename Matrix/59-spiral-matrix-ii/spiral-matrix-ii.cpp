class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n, vector<int>(n, 0));
        int num = 1;
        int top = 0, bottom = n-1, left = 0, right = n-1;

        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++)
                spiral[top][i] = num++;
            top++;
            
            for(int i = top; i <= bottom; i++)
                spiral[i][right] = num++;
            right--;
         
            for(int i = right; i >= left; i--)
                spiral[bottom][i] = num++;
            bottom--;

            for(int i = bottom; i >= top; i--)
                spiral[i][left] = num++;
            left++;
        }

        return spiral;
    }
};