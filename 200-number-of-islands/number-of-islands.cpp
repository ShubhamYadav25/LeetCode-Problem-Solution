class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int islands = 0;

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1') {
                    islands++;
                    grid[r][c] = '0';  // mark as visited
                    queue<pair<int, int>> q;
                    q.push({r, c});

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (auto [dx, dy] : directions) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};