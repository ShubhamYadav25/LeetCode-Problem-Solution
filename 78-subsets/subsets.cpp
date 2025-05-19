class Solution {
public:
void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
        result.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
           
            // Include
            path.push_back(nums[i]);

            // Recurse with next index
            backtrack(i + 1, nums, path, result);

            // Backtrack (undo the choice)
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result;
        vector<int> path;
        backtrack(0, nums, path, result);
        return result;
    }
};