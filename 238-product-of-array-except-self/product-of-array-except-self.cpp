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
        vector<int> left(n, 1), right(n, 1), ans(n);

        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }
};