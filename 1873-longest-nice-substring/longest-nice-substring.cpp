class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";

        unordered_set<char> chars(s.begin(), s.end());

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            // if the other case doesn't exist
            if (chars.count(tolower(c)) && chars.count(toupper(c))) continue;

            // split and solve recursively
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return left.size() >= right.size() ? left : right;
        }

        // if all characters are valid
        return s;
    }
};