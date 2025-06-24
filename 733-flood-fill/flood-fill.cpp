class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int m = image.size(), n = image[0].size();
        int oldColor = image[sr][sc];

        if (oldColor == newColor)
            return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == oldColor) {
                    image[nx][ny] = newColor;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};