class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int, int> count;
        
        // duplicate decide no of rows in matrix
        int maxFreq = 0;
        for (int num : nums) {
            count[num]++;
            maxFreq = max(maxFreq, count[num]);
        }

        vector<vector<int>> res(maxFreq);

        // use to track used num
        unordered_map<int, int> usage;

        for (int num : nums) {
            int row = usage[num];     
            res[row].push_back(num);   
            usage[num]++;              
        }

        return res;
    }
};