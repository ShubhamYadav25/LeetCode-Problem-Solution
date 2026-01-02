class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int delta[101] = {0}; 
        const int offset = 1950;

        for (const auto& log : logs) {
            ++delta[log[0] - offset]; // birth +1
            --delta[log[1] - offset]; // death -1
        }

        int maxPop = 0, curPop = 0, bestYear = offset;
        for (int y = 0; y < 101; ++y) {
            curPop += delta[y];
            if (curPop > maxPop) {
                maxPop = curPop;
                bestYear = offset + y;
            }
        }
        return bestYear;
    }
};