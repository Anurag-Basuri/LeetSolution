class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        # Create adjacency list representation of the graph
        adj = {i: [] for i in range(1, n + 1)}  # Using 1-based indexing

        for u, v, w in times:
            adj[u].append((v, w))

        # Min-heap (priority queue) to always process the shortest known path first
        pq = [(0, k)]  # (current time, current node)
        network = {i: float('inf') for i in range(1, n + 1)}
        network[k] = 0

        while pq:
            cur_time, cur = heapq.heappop(pq)

            # Explore all adjacent nodes
            for new_cur, weight in adj[cur]:
                new_time = cur_time + weight

                if new_time < network[new_cur]:
                    network[new_cur] = new_time
                    heapq.heappush(pq, (new_time, new_cur))

        # Find the maximum delay time among all reachable nodes
        max_time = max(network.values())
        return max_time if max_time != float('inf') else -1
