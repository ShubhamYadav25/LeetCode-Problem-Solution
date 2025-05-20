class Solution {
public:
void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(current);
            return;
        }
        
        //exclude nums[start]
        backtrack(nums, start + 1, current, result);
        
        // include nums[start]
        current.push_back(nums[start]);
        backtrack(nums, start + 1, current, result);
        current.pop_back(); // backtrack (undo the inclusion)
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};