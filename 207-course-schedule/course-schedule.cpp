class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& p : prerequisites) {
            int to = p[0], from = p[1];
            graph[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            count++;

            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return count == numCourses;
    }
};