class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(int index, string &s, vector<string> &path) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                string part = s.substr(index, i - index + 1); // s[index..i]
                path.push_back(part);
                backtrack(i + 1, s, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(0, s, path);
        return res;
    }
};