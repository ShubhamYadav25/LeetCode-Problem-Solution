class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        // in DESC
        for (int i = 0; i < m; ++i) {
            sort(nums[i].rbegin(), nums[i].rend());
        }

        int totalSum = 0;

        // Columwise max sum
        for (int col = 0; col < n; ++col) {
            int maxVal = 0;
            for (int row = 0; row < m; ++row) {
                maxVal = max(maxVal, nums[row][col]);
            }
            totalSum += maxVal;
        }

        return totalSum;
    }
};