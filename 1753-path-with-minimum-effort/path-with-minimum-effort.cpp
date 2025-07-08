class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> minEffort(m, vector<int>(n, INT_MAX));
        minEffort[0][0] = 0;

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<>> minHeap;

        minHeap.push({0, 0, 0}); // (effort, row, col)

        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!minHeap.empty()) {
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            // If we reached the target
            if (x == m - 1 && y == n - 1) {
                return effort;
            }

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {

                    int stepEffort = abs(heights[nx][ny] - heights[x][y]);

                    int pathEffort = max(effort, stepEffort);

                    if (pathEffort < minEffort[nx][ny]) {
                        minEffort[nx][ny] = pathEffort;
                        minHeap.push({pathEffort, nx, ny});
                    }
                }
            }
        }

        return 0; 
    }
};