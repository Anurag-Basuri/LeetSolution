class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans(n);
        for(auto rich:richer){
            graph[rich[0]].push_back(rich[1]);
            indegree[rich[1]]++;
        }

        iota(ans.begin(), ans.end(), 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i:graph[node]){
                if( quiet[ans[node]] < quiet[ans[i]])
                    ans[i] = ans[node];

                if(--indegree[i] == 0)
                    q.push(i);
            }
        }

        return ans;
    }
};