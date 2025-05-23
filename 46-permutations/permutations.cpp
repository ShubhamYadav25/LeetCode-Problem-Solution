class Solution {
public:
set<vector<int>> visited;
vector<vector<int>> result;

    void generatePermutations(vector<int>& nums, int index) {
        if (index == (int)nums.size()) {
            if (visited.find(nums) == visited.end()) {
                visited.insert(nums);
                result.push_back(nums);
            }
            return;
        }

        for (int i = index; i < (int)nums.size(); ++i) {
            swap(nums[index], nums[i]);
            generatePermutations(nums, index + 1);
            swap(nums[index], nums[i]); 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         visited.clear();
        result.clear();
        generatePermutations(nums, 0);
        return result;
    }
};