class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<int> ind(numCourses, 0);
        vector<int> topo;
        vector<vector<int>> adj(numCourses);
        vector<vector<bool>> reachable(numCourses,
                                       vector<bool>(numCourses, false));

        // calc build + indegree
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            ind[p[1]]++;
        }

        queue<int> q;
        // insert in queue if ind = 0
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 0)
                q.push(i);
        }

        // topo sort
        while (!q.empty()) {
            int u = q.front();
            topo.push_back(u);

            q.pop();

            // reduce indegree
            for (int v : adj[u]) {

                // so basically here v is reachable from u
                reachable[u][v] = true;

                // all prereqs (followers) of u are also prereqs (followrs) of v
                for (int k = 0; k < numCourses; k++) {
                    if (reachable[k][u]) // checking who is prereq of u via k
                                         // =0,1,2
                        reachable[k][v] = true;
                }
                ind[v]--;
                if (ind[v] == 0)
                    q.push(v);
            }
        }

        vector<bool> ans;
        for (auto& q : queries)
            ans.push_back(reachable[q[0]][q[1]]);
        return ans;

        return ans;
    }
};