class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int prefix = 1, suffix = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            prefix = (prefix == 0 ? 1 : prefix) * nums[i];
            suffix = (suffix == 0 ? 1 : suffix) * nums[n - 1 - i];

            maxProduct = std::max(maxProduct, std::max(prefix, suffix));
        }

    return maxProduct;
    }
};