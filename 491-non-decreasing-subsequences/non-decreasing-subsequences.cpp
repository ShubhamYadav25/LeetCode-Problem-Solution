class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int idx, vector<int>& curr) {
        if (curr.size() >= 2) {
            ans.push_back(curr);
        }

        unordered_set<int> used;  
        for (int i = idx; i < nums.size(); i++) {

            // skip duplicates at same level
            if (used.count(nums[i])) continue;

            // maintain non-decreasing property
            if (!curr.empty() && nums[i] < curr.back()) continue;

            used.insert(nums[i]);     // mark number as used at this depth
            curr.push_back(nums[i]);   // include

            dfs(nums, i + 1, curr);

            curr.pop_back();           // backtrack
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        dfs(nums, 0, curr);
        return ans;
    }
};