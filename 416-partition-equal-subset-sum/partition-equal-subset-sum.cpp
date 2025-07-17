class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                // If I could already make sum i, keep it as true 
                // OR
                // If I could make sum i - num before, then by adding num, I can now make sum i.
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }
};