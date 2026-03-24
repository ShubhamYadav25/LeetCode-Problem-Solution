class Solution {
public:
    // nums = [1, 2, 3, 4]

    // Left products:
    // [1, 1, 2, 6]

    // Right products:
    // [24, 12, 4, 1]

    // Answer:
    // [24, 12, 8, 6]
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // left product
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // right product
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};