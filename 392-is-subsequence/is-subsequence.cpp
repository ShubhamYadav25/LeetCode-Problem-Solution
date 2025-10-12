class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Every entry in pos tells you where that letter occurs in t.
        /**
            pos[0] ('a') = [0]
            pos[1] ('b') = [2]
            pos[2] ('c') = [5]
            pos[3] ('d') = [4]
            pos[4] ('e') = []
            pos[5] ('f') = []
            pos[6] ('g') = [3]
            pos[7] ('h') = [1]
            pos[8] ('i') = []
        */
        vector<vector<int>> pos(26);
        for (int i = 0; i < t.size(); ++i)
            pos[t[i] - 'a'].push_back(i);

        int prev = -1; // previous matched index in t
        for (char c : s) {
            auto& vec = pos[c - 'a'];
            if (vec.empty())
                return false;

            // find smallest index > prev
            auto it = upper_bound(vec.begin(), vec.end(), prev);
            if (it == vec.end())
                return false;

            prev = *it;
        }
        return true;
    }
};