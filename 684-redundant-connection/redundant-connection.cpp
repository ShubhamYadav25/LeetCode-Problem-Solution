class Solution {
public:
    bool isConnected(int start, int end, vector<vector<int>> &graph, vector<bool> &visited) {
        if (start == end) return true;

        visited[start] = true;

        for (int neighbor : graph[start]) {
            if (!visited[neighbor]) {
                if (isConnected(neighbor, end, graph, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();  
        vector<vector<int>> graph(n + 1);  

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n + 1, false);
            if (!graph[u].empty() && !graph[v].empty()) {
                if (isConnected(u, v, graph, visited)) {
                    return edge;
                }
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};