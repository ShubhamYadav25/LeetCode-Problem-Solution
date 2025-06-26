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
        if(n == 1) return true;
        vector<vector<int>> adj(n);

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n);
        return dfs(adj, source, destination, vis);
    }
};