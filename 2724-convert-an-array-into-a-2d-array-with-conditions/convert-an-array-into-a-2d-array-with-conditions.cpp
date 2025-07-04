class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {  
       int freq[201] = {}; 
        vector<vector<int>> res;

        for (int num : nums) {
            int row = freq[num];

            // If current row doesn't exist yet, create it
            if (res.size() <= row)
                res.push_back({});

            res[row].push_back(num);

            freq[num]++;
        }

        return res;
    }
};