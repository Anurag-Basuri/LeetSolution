class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int cur, int n){
        color[cur] = n;

        for(int& i:graph[cur]){
            if(color[i] == -1){
                if(dfs(graph, color, i, !n) == false)
                    return false; 
            }
            else if(color[i] == n)
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1 && dfs(graph, color, i, 1) == false)
                return false;
        }

        return true;
    }
};