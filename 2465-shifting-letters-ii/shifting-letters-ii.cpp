class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> d(n + 1);          
        
        // same code check diff array in page
        for (auto &v : shifts) {       
            int l = v[0], r = v[1], dir = v[2] ? 1 : -1;
            d[l] += dir;
            if (r + 1 < n) d[r + 1] -= dir;
        }

        int cur = 0;
        for (int i = 0; i < n; ++i) {  
            cur += d[i];
            int shifted = ((s[i] - 'a') + cur) % 26;
            if (shifted < 0) shifted += 26;   
            s[i] = 'a' + shifted;
        }
        return s;
    }
};