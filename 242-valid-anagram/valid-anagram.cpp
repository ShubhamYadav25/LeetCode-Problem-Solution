class Solution {
public:
    bool isAnagram(string s1, string s2) {
         if (s1.length() != s2.length()) return false;
        unordered_map<char, int> freq;

        for (char c : s1) freq[c]++;
        for (char c : s2) {
            if (--freq[c] < 0) return false;
        }

        return true;
    }
};