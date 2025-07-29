class Solution {
private:
    void dfs(int node, unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited) {
        stack<int> stk;
        stk.push(node);

        while (!stk.empty()) {
            int current = stk.top(); stk.pop();
            if (visited.count(current)) continue;
            visited.insert(current);

            for (int neighbor : adjList[current]) {
                if (!visited.count(neighbor)) {
                    stk.push(neighbor);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
         int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        unordered_map<int, vector<int>> adjList;

        // adjacency list
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    int node = r * cols + c;
                    // Include the node even if it has no neighbors
                    adjList[node] = {};
                    vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
                    for (auto [dr, dc] : directions) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                            int neighbor = nr * cols + nc;
                            adjList[node].push_back(neighbor);
                        }
                    }
                }
            }
        }

        // DFS
        unordered_set<int> visited;
        int islandCount = 0;

        for (const auto& [node, neighbors] : adjList) {
            if (visited.count(node) == 0) {
                dfs(node, adjList, visited);
                ++islandCount;
            }
        }

        return islandCount;
    }
};