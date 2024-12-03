class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.length();

        if(n < k) return false;

        unordered_set<string> st;

        if(st.find(s.substr(0, k)) == st.end()) st.insert(s.substr(0, k));

        for(int i = k; i < n; i++) {

            if(st.find(s.substr(i - k + 1, k)) == st.end()) st.insert(s.substr(i - k + 1, k));
        }

        return st.size() == pow(2, k);
        
    }
};