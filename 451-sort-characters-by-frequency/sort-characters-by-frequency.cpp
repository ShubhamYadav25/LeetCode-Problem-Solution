class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);

        for (char c : s) {
            freq[c]++;
        }

        vector<pair<int, char>> arr;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                arr.push_back({freq[i], (char)i});
            }
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        string ans = "";
        for (auto &p : arr) {
            ans.append(p.first, p.second);
        }

        return ans;
    }
};
