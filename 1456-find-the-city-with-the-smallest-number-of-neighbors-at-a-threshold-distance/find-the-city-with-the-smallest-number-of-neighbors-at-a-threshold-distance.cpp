class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n); 

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int result = -1;
        int minReachable = n + 1;

        for (int start = 0; start < n; ++start) {
            vector<int> dist(n, INT_MAX);
            dist[start] = 0;

            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            pq.push({0, start});

            while (!pq.empty()) {
                auto [currDist, node] = pq.top(); pq.pop();

                if (currDist > dist[node]) continue;

                for (auto& [neighbor, weight] : graph[node]) {
                    int newDist = currDist + weight;
                    if (newDist < dist[neighbor]) {
                        dist[neighbor] = newDist;
                        pq.push({newDist, neighbor});
                    }
                }
            }

            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (i != start && dist[i] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= minReachable) {
                minReachable = count;
                result = start;
            }
        }

        return result;
    }
};