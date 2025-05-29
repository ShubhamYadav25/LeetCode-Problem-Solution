class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> m;

    void includeExclude(int ind, vector<int>& nums, vector<int>& curr) {
        if (ind <= nums.size()) {
            m.insert(curr);
        }

        for (int i = ind; i < nums.size(); i++) {
            // Skip duplicates at the same level
            if (i > ind && nums[i] == nums[i - 1]) continue;

            // include
            curr.push_back(nums[i]);
            includeExclude(i + 1, nums, curr); 

            // exclude
            curr.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        includeExclude(0, nums, curr);

        for (auto& a : m) {
            ans.push_back(a);
        }
        return ans;
    }
};