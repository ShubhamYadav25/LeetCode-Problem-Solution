class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]); // sentinel

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {

            // each row in histogram
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            // largest rectangle algo in each row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};