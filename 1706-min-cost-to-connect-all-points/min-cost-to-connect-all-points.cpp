class DSU {
    public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

class Solution {
public: 
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges; 

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + 
                           abs(points[i][1] - points[j][1]);
                edges.emplace_back(dist, i, j);
            }
        }     

        sort(edges.begin(), edges.end());
        
        DSU dsu(n);
        int totalCost = 0, connected = 0;

        for (auto &[cost, u, v] : edges) {
            if (dsu.unite(u, v)) {
                totalCost += cost;
                connected++;
                if (connected == n-1) break; // MST complete
            }
        }

        return totalCost;   
    }
};