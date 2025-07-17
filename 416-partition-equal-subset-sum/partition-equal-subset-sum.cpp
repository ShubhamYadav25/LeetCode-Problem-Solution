class Solution {
public:
     bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;
        if (total % 2 != 0) return false; 

        int target = total / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return canMakeSum(nums, 0, target, memo);
    }

    bool canMakeSum(vector<int>& nums, int i, int target, vector<vector<int>>& memo) {
        if (target == 0) return true;    
        if (i >= nums.size() || target < 0) return false; 

        if (memo[i][target] != -1) {
            return memo[i][target];
        }

        // Pick or leave the current number
        bool pick = canMakeSum(nums, i + 1, target - nums[i], memo);
        bool leave = canMakeSum(nums, i + 1, target, memo);

        memo[i][target] = pick || leave;    
        return memo[i][target];
    }
};