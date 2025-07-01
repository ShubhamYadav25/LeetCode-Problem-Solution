class DSU {
   vector<int> parent;
   vector<int> rank;

public:

    DSU(int size) : parent(size), rank(size, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

   int Find(int x) {
        if (parent[x] != x)
            parent[x] = Find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {  
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        for(auto v : edges){
            if(dsu.Find(v[0]) == dsu.Find(v[1])) {
                return v;
            }
            dsu.Union(v[0], v[1]);
        }

        return {};
    }
};