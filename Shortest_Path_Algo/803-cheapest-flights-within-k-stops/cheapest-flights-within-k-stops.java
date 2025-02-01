import java.util.*;

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<int[]>> graph = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] flight : flights) {
            graph.get(flight[0]).add(new int[]{flight[1], flight[2]});
        }

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{src, 0, 0}); // {current node, total cost, stops}

        int[] minCost = new int[n]; // To track the minimum cost
        Arrays.fill(minCost, Integer.MAX_VALUE);
        minCost[src] = 0;

        while (!q.isEmpty()) {
            int[] top = q.poll();
            int cur = top[0], cost = top[1], stops = top[2];

            if (stops > k) continue;

            for (int[] flight : graph.get(cur)) {
                int nextNode = flight[0], price = flight[1];

                if (cost + price < minCost[nextNode]) {
                    minCost[nextNode] = cost + price;
                    q.add(new int[]{nextNode, cost + price, stops + 1});
                }
            }
        }

        return minCost[dst] == Integer.MAX_VALUE ? -1 : minCost[dst];
    }
}
