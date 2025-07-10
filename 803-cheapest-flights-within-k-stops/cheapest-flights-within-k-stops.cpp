class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         
        // adj list
        vector<pair<int, int>> adj[n];

        for(const auto& flight : flights){
            int from = flight[0], to = flight[1], price = flight[2];
            adj[from].push_back({to, price});
        }

        vector<int> costs(n, INT_MAX);
        costs[src] = 0;

        // {city, currentCost, stopsTaken}
        queue<tuple<int , int , int>> q;
        q.push({src, 0, 0});

        while(!q.empty()){
            
            auto [city, currentCost, stopsTaken] = q.front();
            q.pop();

            if(stopsTaken > k) continue;

            // update cost near to city
            for (const auto& [nextCity, price] : adj[city]) {
                int updatedCost = currentCost + price;
                if(updatedCost < costs[nextCity]){
                    costs[nextCity] = updatedCost;
                    q.push({nextCity, updatedCost, stopsTaken + 1});
                }
            }
            
        }

        return (costs[dst] == INT_MAX) ? -1 : costs[dst];
    }
};