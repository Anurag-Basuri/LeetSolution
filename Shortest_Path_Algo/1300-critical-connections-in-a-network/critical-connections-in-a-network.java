class Solution {
    private int time = 0;

    public void dfs(int node, int parent, List<List<Integer>> graph, List<List<Integer>> bridges, List<Integer> disc, List<Integer> low) {
        disc.set(node, time);
        low.set(node, time);
        time++;
        for (int neighbor : graph.get(node)) {
            if (neighbor == parent) {
                continue;
                }
            if (disc.get(neighbor) == -1) {
                dfs(neighbor, node, graph, bridges, disc, low);
                low.set(node, Math.min(low.get(node), low.get(neighbor)));
               if (low.get(neighbor) > disc.get(node)) {
                    bridges.add(Arrays.asList(node, neighbor));
                }
            } else {
               low.set(node, Math.min(low.get(node), disc.get(neighbor)));
            }
        }
    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (List<Integer> conn : connections) {
            int u = conn.get(0);
            int v = conn.get(1);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        List<Integer> disc = new ArrayList<>(Collections.nCopies(n, -1));
        List<Integer> low = new ArrayList<>(Collections.nCopies(n, -1));
        List<List<Integer>> bridges = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (disc.get(i) == -1) {
                dfs(i, -1, graph, bridges, disc, low);
            }
        }

        return bridges;
    }
}