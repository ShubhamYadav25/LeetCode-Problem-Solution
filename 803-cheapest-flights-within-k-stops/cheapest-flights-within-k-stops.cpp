class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<int> costs(n, INT_MAX);
        costs[src] = 0;

        // RELAXATION ONLY at most k times
        for (int i = 0; i <= k; i++) {
            vector<int> temp = costs;
            for (const auto& flight : flights) {
                int u = flight[0], v = flight[1], w = flight[2];

                if (costs[u] != INT_MAX && costs[u] + w < temp[v]) {
                    temp[v] = costs[u] + w;
                }
            }
            costs = temp;
        }

        return (costs[dst] == INT_MAX) ? -1 : costs[dst];
    }
};