class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int size) {
        parent.resize(size, -1);
        rank.resize(size, 0);    
    } 

    int Find(int v) {
        if (parent[v] == -1)
            return v;
        return parent[v] = Find(parent[v]);
    } 

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    vector<int>& getParents() {
        return parent;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        
        // 1d matrix using ids = i * colm + j
        DSU dsu(rows * cols);

        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        // First we do union of each cell to its neighbour
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {

                    // 1d matrix ids
                    int current = i * cols + j;

                    for (auto& dir : directions) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        // boundry limits
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == '1') {
                            int neighbor = ni * cols + nj;
                            dsu.Union(current, neighbor);
                        }
                    }
                }
            }
        }

        // Now we have sets ready, to find island 
        // we iterate over every cell if their belong to parent then no issue (one island)
        // if they belong to separate set the parent will be different == diffetent island we increase count
        
        // I think we can optimize it more by using visited array (will check later)
        unordered_set<int> uniqueIslands;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    int id = i * cols + j;
                    uniqueIslands.insert(dsu.Find(id));
                }
            }
        }

        return uniqueIslands.size();
    }
};