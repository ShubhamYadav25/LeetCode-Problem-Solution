class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pb] = pa;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dsu(n);

        // union pairs
        for (auto& p : pairs)
            dsu.unite(p[0], p[1]);

        //group indices by root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[dsu.find(i)].push_back(i);

        // ans
        string result = s;

        for (auto& entry : groups) {
            vector<int>& indices = entry.second;
            vector<char> chars;

            for (int idx : indices)
                chars.push_back(s[idx]);

            sort(indices.begin(), indices.end());
            sort(chars.begin(), chars.end());

            for (int i = 0; i < indices.size(); i++)
                result[indices[i]] = chars[i];
        }

        return result;
    }
};
