class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for(auto v : times){
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> distance(n + 1, 1e9);
        distance[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int currDist = top.first;
            int node = top.second;

            for(auto v : adj[node]) {
                int neighbor = v.first;
                int weight = v.second;
                if(distance[neighbor] > currDist + weight) {
                    distance[neighbor] = currDist + weight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        int d = 0;
        for(int i = 1; i <= n; ++i){
            if(distance[i] == 1e9) return -1;
            d = max(d, distance[i]);
        }

        return d;

    }
};