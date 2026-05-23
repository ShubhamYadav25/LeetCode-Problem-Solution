class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;
        
        for (int i = n - k; i < n; ++i) {
            rightSum += cardPoints[i];
        }
        
        int best = rightSum;
        
        for (int i = 0; i < k; ++i) {
            leftSum  += cardPoints[i];        
            rightSum -= cardPoints[n - k + i];   
            best = max(best, leftSum + rightSum);
        }
        
        return best;
    }
};