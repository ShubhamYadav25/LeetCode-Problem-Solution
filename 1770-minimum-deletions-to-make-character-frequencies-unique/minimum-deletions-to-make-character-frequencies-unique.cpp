class Solution {
public:
    int minDeletions(string s) {

        unordered_map<char, int> m;

        for (auto i : s) {
            m[i]++;
        }

        int x = 0;

        // using a set so that we not need to go over map to check duplicate
        // freq
        unordered_set<int> usedFreq;
        int deletetion = 0;

        for (auto& p : m) {
            int freq = p.second;
            while (freq > 0 && usedFreq.count(freq)) {
                freq--;
                deletetion++;
            }
            if (freq > 0)
                usedFreq.insert(freq);
        }

        return deletetion;
    }
};