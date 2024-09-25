class Solution {
public:
    string reverseWords(string data) {
        stringstream s(data);
        string str;
        
        stack<string>st;
        while(s>>str){
            st.push(str);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top() + " ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};