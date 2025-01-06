class Solution {
public:
    int countGoodSubstrings(string s) {
         int n = s.size();
    if (n < 3) return 0; // No substrings of length 3

    int result = 0;
    vector<int> freq(26, 0); // Frequency array for characters

    // Initialize the frequency array for the first window
    for (int i = 0; i < 3; ++i) {
        freq[s[i] - 'a']++;
    }

    // Check if the first window is good
    if (freq[s[0] - 'a'] == 1 && freq[s[1] - 'a'] == 1 && freq[s[2] - 'a'] == 1) {
        result++;
    }

    // Slide the window through the string
    for (int i = 3; i < n; ++i) {
        // Remove the leftmost character of the previous window
        freq[s[i - 3] - 'a']--;
        // Add the new character to the window
        freq[s[i] - 'a']++;

        // Check if the current window is good
        if (freq[s[i - 2] - 'a'] == 1 && freq[s[i - 1] - 'a'] == 1 && freq[s[i] - 'a'] == 1) {
            result++;
        }
    }

    return result;
        
    }
};