class Solution {
public:
     vector<vector<int>> s;

    void back(vector<int>& candidates, int target, vector<int>& ans, int ind, int sum) {
        if (sum == target) {
            s.push_back(ans);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
           
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            if (sum + candidates[i] > target) break; 

            ans.push_back(candidates[i]);
            back(candidates, target, ans, i + 1, sum + candidates[i]);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
        s.clear(); 
        vector<int> ans;
        back(candidates, target, ans, 0, 0);
        return s;
    }
};