class Solution {
public:

    void dfs(vector<vector<int>>& rooms, int index, vector<bool>& visited){
        
        visited[index] = true;
        for(auto v : rooms[index]){
            if(!visited[v]){
                dfs(rooms, v, visited);
            }
        }

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        dfs(rooms, 0, visited);
       
        for(auto i : visited){
            if(!i) return false; 
        }

        return true;

    }
};