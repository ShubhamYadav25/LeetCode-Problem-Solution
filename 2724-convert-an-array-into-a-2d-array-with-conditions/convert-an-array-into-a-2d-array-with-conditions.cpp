class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
         unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxRows = 0;
        for (const auto& [num, count] : freq) {
            maxRows = max(maxRows, count);
        }

        vector<vector<int>> res(maxRows);

        for (const auto& [num, count] : freq) {
            for (int i = 0; i < count; i++) {
                res[i].push_back(num);  
            }
        }

        return res;
    }
};