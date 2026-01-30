class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        unordered_map<int, vector<int>> stopToRoutes;
        int n = routes.size();

        for(int i = 0; i < n; i++) {
            for(int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        if(!stopToRoutes.count(source) || !stopToRoutes.count(target))
            return -1;

        queue<int> q;
        unordered_set<int> visitedRoutes;
        unordered_set<int> visitedStops;

        for(int route : stopToRoutes[source]) {
            q.push(route);
            visitedRoutes.insert(route);
        }

        int buses = 1;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                int route = q.front();
                q.pop();

                for(int stop : routes[route]) {

                    if(stop == target)
                        return buses;

                    if(visitedStops.count(stop)) continue;
                    visitedStops.insert(stop);

                    for(int nextRoute : stopToRoutes[stop]) {
                        if(!visitedRoutes.count(nextRoute)) {
                            visitedRoutes.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
            buses++;
        }

        return -1;
    }
};
