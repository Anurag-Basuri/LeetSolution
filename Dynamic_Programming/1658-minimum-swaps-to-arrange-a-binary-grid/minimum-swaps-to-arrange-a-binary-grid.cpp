class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<int>endZeroes(n,0);
       for(int i = 0; i < n; i++){
        int j = n-1;
        int count = 0;
        while(j >= 0 && grid[i][j] == 0){
            count++;
            j--;
        }
        endZeroes[i] = count;
       }
       int steps = 0;
       for(int i = 0; i < n; i++){
        int need = n - i - 1;
        int j = i;
        while(j < n && endZeroes[j] < need){
            j++;
        }
        while(j == n){
            return -1;
        }
        steps += j - i;
        while(j > i){
            swap(endZeroes[j],endZeroes[j-1]);
            j--;
        }
       }
       return steps;
    }
};