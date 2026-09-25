class dsu {
    vector<int> parent, rank;
    int count;

public:
    dsu(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        
        return parent[x];
    }

    void union_set(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if(rank[xParent] < rank[yParent])
            parent[xParent] = yParent;
        else if(rank[yParent] < rank[xParent])
            parent[yParent] = xParent;
        else {
            parent[yParent] = xParent;
            rank[xParent]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        dsu X(n);
        int totalComponents = n;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && X.find(i) != X.find(j)) {
                    totalComponents--;

                    X.union_set(i, j);
                }

            }
        }

        return totalComponents;
    }
};