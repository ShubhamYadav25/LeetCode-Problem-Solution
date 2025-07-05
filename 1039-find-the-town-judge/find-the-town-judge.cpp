class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n + 1, 0);

        for (const auto& pair : trust) {
            int a = pair[0]; 
            int b = pair[1]; 

            trustScore[a]--; // a loses credibility
            trustScore[b]++; // b gains trust 
        }

        for (int person = 1; person <= n; person++) {
            if (trustScore[person] == n - 1) {
                return person; 
            }
        }

        return -1;
    }
};