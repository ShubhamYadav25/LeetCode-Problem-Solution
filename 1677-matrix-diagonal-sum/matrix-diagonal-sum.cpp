class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += mat[i][i];             
            sum += mat[i][n - 1 - i]; 
        }

        // If n is odd
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};