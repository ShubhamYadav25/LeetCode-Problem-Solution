class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (const auto& v : times) {
        adj[v[0]].emplace_back(v[1], v[2]);
    }

    vector<int> distance(n + 1, INT_MAX);
    distance[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, k);

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        if (currDist > distance[node]) continue; 

        for (const auto& [neighbor, weight] : adj[node]) {
            if (distance[neighbor] > currDist + weight) {
                distance[neighbor] = currDist + weight;
                pq.emplace(distance[neighbor], neighbor);
            }
        }
    }

    int maxDist = 0;
    for (int i = 1; i <= n; ++i) {
        if (distance[i] == INT_MAX) return -1;
        maxDist = max(maxDist, distance[i]);
    }

    return maxDist;

    }
};