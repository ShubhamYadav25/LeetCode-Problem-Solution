class Solution {
public:

    string reverseWords(string s) {
        // 
        // Create a stringstream object
        stringstream ss(s);

        // Variable to hold each word
        string word;

        // Vector to store the words
        vector<string> words;

        // Extract words from the sentence
        while (ss >> word) {

            // Add the word to the vector
            words.push_back(word);
        }
        
        string ans = "";
        
        for(auto str : words){
            reverse(str.begin(), str.end());
            ans += str + " ";
        }
        ans.pop_back();
        
        return ans;
    }
};