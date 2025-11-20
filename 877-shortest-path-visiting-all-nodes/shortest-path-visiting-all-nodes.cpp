class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1; // all bits on means need all node visited

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // store node and its bit Node 0 and bit 1
        for (int i = 0; i < n; ++i) {
            int startMask = 1 << i;
            q.emplace(i, startMask);
            visited[i][startMask] = true;
        }

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [u, mask] = q.front();
                q.pop();
                if (mask == target)
                    return dist; // first time = shortest

                for (int v : graph[u]) { // use real neighbour list
                    int nmask = mask | (1 << v);
                    if (!visited[v][nmask]) {
                        visited[v][nmask] = true;
                        q.emplace(v, nmask);
                    }
                }
            }
            ++dist;
        }
        return -1; // never (graph is connected per problem)
    }
};