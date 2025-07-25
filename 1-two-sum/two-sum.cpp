class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        map.reserve(nums.size());  // preallocate to avoid rehashing

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
   
};