class Solution {
public:
    static const int MOD = 1e9 + 7;

    void dijkstra(int start, vector<vector<pair<int, int>>>& graph,
                  vector<long long>& distance, vector<long long>& ways) {

        int n = graph.size();

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, start});

        while (!pq.empty()) {
            auto [dist, city] = pq.top();
            pq.pop();

            if (dist > distance[city])
                continue;

            for (auto [next_city, weight] : graph[city]) {
                long long newDist = dist + weight;

                // Case 1: strictly shorter path
                if (newDist < distance[next_city]) {
                    distance[next_city] = newDist;
                    ways[next_city] = ways[city];
                    pq.push({newDist, next_city});
                }
                // Case 2: another shortest path
                else if (newDist == distance[next_city]) {
                    ways[next_city] = (ways[next_city] + ways[city]) % MOD;
                }
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        // Build graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto& r : roads) {
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> distance(n, 1e18);
        vector<long long> ways(n, 0);

        distance[0] = 0;
        ways[0] = 1;

        dijkstra(0, graph, distance, ways);

        return ways[n - 1] % MOD;
    }
};
