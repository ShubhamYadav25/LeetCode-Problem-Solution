class Solution {
public:
    bool isValid(string s) {
        
        stack<int> st;
        if(s.length() == 1) return false;

        for(int i = 0; i< s.length();i++){


            if(s[i] == ')'){
                
                if(!st.empty()){
                    char x = st.top();
                    if(x != '(') return false;
                    st.pop();
                }
                else {
                st.push(s[i]);
            }
                
            }else if (s[i] == '}'){
                if(!st.empty()){
                    char x = st.top();
                    if(x != '{') return false;
                    st.pop();
                }
                else {
                st.push(s[i]);
            }
            }else if(s[i] == ']'){
                if(!st.empty()){
                    char x = st.top();
                    if(x != '[') return false;
                    st.pop();
                }
                else {
                st.push(s[i]);
            }
            }else {
                st.push(s[i]);
            }
        }

        if(!st.empty()) return false;

        return true;
    }
};