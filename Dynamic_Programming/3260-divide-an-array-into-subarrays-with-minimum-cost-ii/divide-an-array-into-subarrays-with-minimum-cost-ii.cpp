class Solution {
public:

    void add(int num,int k,multiset<int> &smallest,multiset<int> &rem,long long&sum){
        if(smallest.size()<k-1){
            smallest.insert(num);
            sum+=num;
        }
        else{
            auto it = prev(smallest.end());
            if(num < *it){
                smallest.insert(num);
                sum+=num;
                
            }
            else{
                rem.insert(num);
            }
        }
        balance(smallest,k,rem,sum);
    }

    void remove(int num,int k,multiset<int> &smallest,multiset<int> &rem,long long &sum){
        auto it = smallest.find(num);
        if(it!=smallest.end()){
            sum-=*it;
            smallest.erase(it);
            
        }
        else{
            auto it = rem.find(num);
            rem.erase(it);
        }
        balance(smallest,k,rem,sum);
    }

    void balance(multiset<int> &smallest,int &k,multiset<int> &rem,long long &sum){
        if(smallest.size()>=k){
            auto it = prev(smallest.end());
            sum-=(*it);
            rem.insert(*it);
            smallest.erase(it);
        }
        else if(smallest.size()<k-1){
            auto it = rem.begin();
            if(it!=rem.end()){
                smallest.insert(*it);
                sum+=*it;
                rem.erase(it);
            }
           
        }
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> smallest; // will be having smallest k element
        multiset<int> rem;
        int size=nums.size();
        int l=1,r=l; 
        long long sum=0,ans=LLONG_MAX;
        while(r<=l+dist){
            add(nums[r],k,smallest,rem,sum);
            if(smallest.size()==k-1){
                ans=min(ans,sum);
            }
            r++;
        }
        while(r<size){
            add(nums[r],k,smallest,rem,sum);
            remove(nums[l],k,smallest,rem,sum);
            l++;r++;
            if(smallest.size()==k-1){
                ans=min(ans,sum);
            }
        }
        return ans+nums[0];
    }
};