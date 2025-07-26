class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketPair = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            // If it's a closing bracket
            if (bracketPair.count(ch)) {
                if (st.empty() || st.top() != bracketPair[ch]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket
                st.push(ch);
            }
        }

        return st.empty();
    }
};