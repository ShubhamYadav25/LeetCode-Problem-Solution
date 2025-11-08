class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [](char c) {
            static const string vowels = "aeiouAEIOU";
            return vowels.find(c) != string::npos;
        };

        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i]))
                i++;
            while (i < j && !isVowel(s[j]))
                j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};