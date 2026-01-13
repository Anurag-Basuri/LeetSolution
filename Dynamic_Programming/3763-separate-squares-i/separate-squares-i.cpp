class Solution {
public:
    double check(double m,vector<vector<int>> &v)
    {
        double area=0;
        for(int i=0;i<v.size();i++)
        {
            double s=min((double)v[i][1]+v[i][2],m);
            if(v[i][1]>m)
            continue;
            else
            area+=v[i][2]*(s-(double)v[i][1]);
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double start=0.0;
        double  total=0;
        double end=0;
        int n=squares.size();
        for(int i=0;i<n;i++)
        {
            total+=1.0*squares[i][2]*squares[i][2];
            end=max(end,(double)squares[i][1]+squares[i][2]);
        }
         
        double ans=0;
        
        for(int i=0;i<=100;i++)
        {
            
            double mid=start+(end-start)/2.0;
            cout<<mid<<endl;
            if(check(mid,squares)>=total/2.0)
            {
                end=mid;
            }
           
            else
            start=mid;


    }
    return (start+end)/2.0;
    }
};