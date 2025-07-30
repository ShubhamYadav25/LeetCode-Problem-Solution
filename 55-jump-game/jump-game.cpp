class Solution {
public:

    bool jump(vector<int>& nums, int i, vector<int>& memo){

        if (i >= nums.size() - 1) return true;
        if (memo[i] != -1) return memo[i];

        for (int step = 1; step <= nums[i]; ++step) {
            if (jump(nums, i + step, memo)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return jump(nums, 0, memo);
    }
};