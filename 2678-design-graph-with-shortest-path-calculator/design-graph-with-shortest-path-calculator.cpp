class Graph {
public:
    int n;
    unordered_map<int, vector<pair<int, int>>> adj;

    Graph(int n, vector<vector<int>>& edges) : n(n) {
         for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);

        dist[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top(); pq.pop();

            if (u == node2) return currDist;

            if (currDist > dist[u]) continue;

            // neighbors
            for (auto& [v, w] : adj[u]) {
                int newDist = currDist + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */