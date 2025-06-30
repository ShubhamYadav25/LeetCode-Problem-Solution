class DSU {
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    DSU(int size) : parent(size), rank(size, 0), count(size) {
        iota(parent.begin(), parent.end(), 0);
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

        count--;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    dsu.Union(i, j);
                }
            }
        }

        return dsu.getCount();
    }
};