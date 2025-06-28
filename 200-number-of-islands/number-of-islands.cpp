class Solution {
public:

    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j, vector<vector<bool>>& v){
        
        // boundry
        if(i < 0 || i >= n || j < 0 || j >= m || (grid[i][j] == '0') ||  v[i][j]){
            return;
        }

        v[i][j] = true;

        // apply dfs in four direction
        dfs(grid, n, m , i - 1 , j, v);
        dfs(grid, n, m , i + 1 , j, v);
        dfs(grid, n, m , i , j -1 , v);
        dfs(grid, n, m , i , j + 1, v);
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> v(n, vector<bool>(m , false));
        int island = 0;
        for(int i=0; i<n;i++){
            for(int j = 0; j< m;j++){
                if(grid[i][j] != '0' && !v[i][j]){
                    island++;
                    dfs(grid, n, m, i, j, v);
                }
            }
        }

        return island;
    }
};