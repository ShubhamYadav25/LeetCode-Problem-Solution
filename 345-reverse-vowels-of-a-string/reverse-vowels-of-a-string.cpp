class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<int, int> m;
        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;
        m['A'] = 1;
        m['E'] = 1;
        m['I'] = 1;
        m['O'] = 1;
        m['U'] = 1;

        int i =0, j = s.length() - 1;

        while(i <= j){
            if(m[s[i]] && m[s[j]]){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(m[s[i]]){
                j--;
            }
            else {
                i++;
            };
        }
        return s;
    }
};