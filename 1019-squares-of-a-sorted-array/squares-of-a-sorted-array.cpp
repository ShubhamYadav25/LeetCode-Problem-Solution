class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (int n : nums) {
            res.push_back(n * n);
        }
        sort(res.begin(), res.end());
        return res;
    }
};