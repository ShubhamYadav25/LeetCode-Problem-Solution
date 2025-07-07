class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<pair<int, int>> adj[101];  
        for (const auto& v : times) {
            adj[v[0]].emplace_back(v[1], v[2]);
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue;
            for (const auto& [nei, weight] : adj[node]) {
                if (dist[nei] > d + weight) {
                    dist[nei] = d + weight;
                    pq.emplace(dist[nei], nei);
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.begin() + n + 1);
        return ans == INT_MAX ? -1 : ans;

    }
};