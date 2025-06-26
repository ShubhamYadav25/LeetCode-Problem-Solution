class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int s, int d, vector<bool>& v){
        if(s == d) return true;
        v[s] = true;
        for(auto i : adj[s]){
            
            if(!v[i]){
                if(dfs(adj, i, d, v)) return true; 
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (node == destination) return true;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};