class DSU {
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    DSU(int size) : parent(size), rank(size, 0), count(0) {
        iota(parent.begin(), parent.end(), 0);
    }

    void setCount(int c) {
        count = c;
    }

    int getCount() const {
        return count;
    }

    int Find(int x) {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
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

        count--;  // Only decrement for a successful union
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        DSU dsu(rows * cols);

        auto getId = [&](int i, int j) {
            return i * cols + j;
        };

        int landCount = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    landCount++;
                }
            }
        }

        dsu.setCount(landCount); 

        // Only right and down to avoid duplicates
        vector<pair<int, int>> directions = {{0,1}, {1,0}};  

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    int currId = getId(i, j);
                    for (auto& dir : directions) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == '1') {
                            int neighborId = getId(ni, nj);
                            dsu.Union(currId, neighborId);
                        }
                    }
                }
            }
        }

        return dsu.getCount();
    }
};