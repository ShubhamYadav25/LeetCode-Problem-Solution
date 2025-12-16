class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // BASE CASE: When we've filled all positions
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Try every number from current position to end
        for (int i = start; i < nums.size(); i++) {
            // Make choice: Put nums[i] at position 'start'
            swap(nums[start], nums[i]);

            // Recurse: Fill next position
            backtrack(nums, start + 1, result);

            // Undo choice: Back to original arrangement
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};