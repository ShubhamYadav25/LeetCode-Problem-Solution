class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
         vector<vector<int>> result;
        int i = 0;
        int j = 0; 

        while (i < (int)firstList.size() && j < (int)secondList.size()) {
            int aStart = firstList[i][0];
            int aEnd   = firstList[i][1];
            int bStart = secondList[j][0];
            int bEnd   = secondList[j][1];

            int start = max(aStart, bStart);
            int end   = min(aEnd, bEnd);

            if (start <= end) {
                result.push_back({start, end});
            }

            if (aEnd < bEnd) {
                ++i; // A ends first move A forward
            } else {
                ++j; // B ends first or ties, move B forward
            }

        }

        return result;
    }
};