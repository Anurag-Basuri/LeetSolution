class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for(int num : nums) pq.push((long) num);
        int count = 0;

        while(pq.size() > 1 && pq.top() < k){
            long a = pq.top(); pq.pop();
            long b = pq.top(); pq.pop();

            pq.push(a * 2 + b);
            count++;
        }

        return count;
    }
};