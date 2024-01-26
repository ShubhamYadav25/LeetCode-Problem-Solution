class Solution {
public:
    bool isSubsequence(string s, string t) {
         int sCount = 0; 
    for (int i = 0; i < t.length() && sCount < s.length(); i++)
        if (s[sCount] == t[i])
            sCount++;
 
    // if count == s length => all character covered
    return (sCount == s.length());
    }
    
};