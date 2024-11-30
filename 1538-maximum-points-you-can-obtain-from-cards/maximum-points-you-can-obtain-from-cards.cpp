class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
       int lSum = 0, rSum = 0, maxS;
        
        for (int i = 0; i < k; i++) lSum += cardPoints[i];
        
        maxS = lSum;
        int end = cardPoints.size() - 1;
        
        for (int i = k - 1; i >= 0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[end--];
            maxS = max(maxS, lSum + rSum);
        }
        
        return maxS;      
    }
};