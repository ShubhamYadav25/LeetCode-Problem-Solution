class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onPath) {
        if (onPath[node]) return true;  // cycle
        if (visited[node]) return false;

        visited[node] = true;
        onPath[node] = true;

        for (int neighbor : graph[node]) {
            if (dfs(neighbor, graph, visited, onPath))
                return true; 
        }

        onPath[node] = false; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); 
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, onPath))
                    return false; 
            }
        }
        return true;
    }
};