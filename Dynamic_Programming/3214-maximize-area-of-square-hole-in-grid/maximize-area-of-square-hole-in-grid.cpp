class Solution {
public:

    int ma(int a,vector<int>& b){
        int ans=2;
        int c=1;
        sort(b.begin(),b.end());

        for(int i=1;i<b.size();i++){
            if(b[i]-b[i-1]==1){
                c++;
                ans=max(ans,c+1);
            }else{
                c=1;
            }
        }
       return ans;

    }


    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        int s=min(ma(m,hBars),ma(n,vBars));
        return s*s;


    }
};