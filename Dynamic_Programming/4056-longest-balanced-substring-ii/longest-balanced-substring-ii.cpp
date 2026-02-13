class Solution {
public:

    int case1(string s,int n){
        int mx=1;
        int cur=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cur++;
            }else{
                cur=1;
            }
            mx=max(cur,mx);
        }
        return mx;
    }
    int subcase2(char a,char b,string s,int n){
        int cnt_a=0;
        int cnt_b=0;
        int mx=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(s[i]==a){
                cnt_a++;
            }else if(s[i]==b){
                cnt_b++;
            }else{
                cnt_a=0;
                cnt_b=0;
                mp.clear();
            }

            int d=cnt_a-cnt_b;

            if(cnt_a==cnt_b){
                mx=max(mx,cnt_a+cnt_b);
            }else{
                if(mp.find(d)!=mp.end()){
                    mx=max(mx,i-mp[d]);
                }else mp[d]=i;
            }
        }
        return mx;
    }

    int case2(string s,int n){
        int ab=subcase2('a','b',s,n);
        int ac=subcase2('a','c',s,n);
        int bc=subcase2('b','c',s,n);
        // cout<<ab<<" "<<ac<<" "<<bc<<endl;
        return max({ab,ac,bc});
    }

    int case3(string s,int n){
        unordered_map<string,int>mp;
        int cnt_a=0;
        int cnt_b=0;
        int cnt_c=0;

        int mx=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                cnt_a++;
            }else if(s[i]=='b'){
                cnt_b++;
            }else{
                cnt_c++;
            }

            int d1=cnt_a - cnt_b;
            int d2=cnt_a - cnt_c;
            string d=to_string(d1)+"_"+to_string(d2);
            
            if(cnt_a==cnt_b && cnt_a==cnt_c){
                mx=max(mx,(cnt_a+cnt_b+cnt_c));
            }else{
                if(mp.find(d)!=mp.end()){
                    mx=max(mx,i-mp[d]);
                }else mp[d]=i;
            }
        }
        return mx;
    }

    int longestBalanced(string s) {
        int n=s.size();
         // Calculate results for all three cases
        int c1 = case1(s, n);  // Case 1: all same characters
        int c2 = case2(s, n);  // Case 2: two characters appear equally
        int c3 = case3(s, n);  // Case 3: all three characters appear equally
        
        // cout<<c1<<" "<<c2<<" "<<c3<<endl;

        // Return the maximum length among all cases
        return max({c1,c2,c3});
    }
};