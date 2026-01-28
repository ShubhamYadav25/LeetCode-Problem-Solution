class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> firstIndex;
        int score = 0;
        int ans = 0;

        for (int i = 0; i < hours.size(); i++) {
            score += (hours[i] > 8 ? 1 : -1);

            // If score is positive, whole interval [0..i] works
            if (score > 0) {
                ans = i + 1;
            }
            // If score-1 appeared before, we found a valid interval
            else if (firstIndex.count(score - 1)) {
                ans = max(ans, i - firstIndex[score - 1]);
            }

            // Store first occurrence only
            if (!firstIndex.count(score)) {
                firstIndex[score] = i;
            }
        }

        return ans;
    }
};