class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        graph = {i: [] for i in range(n)}
        
        for flight in flights:
            graph[flight[0]].append((flight[1], flight[2]))  # (destination, cost)

        q = deque([(src, 0, 0)])  # (current node, total cost, stops)
        min_cost = [sys.maxsize] * n
        min_cost[src] = 0

        while q:
            cur, cost, stops = q.popleft()

            if stops > k:
                continue

            for next_node, price in graph[cur]:
                if cost + price < min_cost[next_node]:
                    min_cost[next_node] = cost + price
                    q.append((next_node, cost + price, stops + 1))

        return -1 if min_cost[dst] == sys.maxsize else min_cost[dst]
