class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // adj list
        vector<vector<int>> graph(numCourses);
        for(auto& v : prerequisites){
                graph[v[1]].push_back(v[0]);
        }

        vector<int> indegree(numCourses, 0);

        for(auto v : prerequisites ){
            indegree[v[0]]++;
        }

        // push indegree 0 to queue
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;

        // pop and reduce indegre
        while(!q.empty()){
            int x = q.front();
            q.pop();
            res.push_back(x);
            // reduce indegree of neighbour
            for(auto neighbour : graph[x]){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0) q.push(neighbour);
            }
        }

        if(res.size() == numCourses) return res;
        else return {};  // Cycle detected; no valid ordering
    }
};