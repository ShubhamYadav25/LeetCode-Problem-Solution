class Solution {
public: 
    bool dfs(int node, vector<bool>& visited, vector<bool>& onPath, stack<int>& st, vector<vector<int>>& adj) {
        visited[node] = true;
        onPath[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (!dfs(neighbor, visited, onPath, st, adj)) {
                    return false; 
                }
            } else if (onPath[neighbor]) {
                return false;  
            }
        }

        onPath[node] = false;
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& v : prerequisites) {
            graph[v[1]].push_back(v[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, visited, onPath, st, graph)) {
                    return {};  // Cycle detected, no valid ordering
                }
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};