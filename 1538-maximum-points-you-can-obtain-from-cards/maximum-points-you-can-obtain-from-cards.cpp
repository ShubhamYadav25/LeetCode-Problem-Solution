/**
Cards: [1, 2, 3, 4, 5, 6, 1]    n = 7, k = 3
              └─────┘
           skip n-k = 4 cards

If you skip [2, 3, 4, 5] (sum = 14), you take 1 + 6 + 1 = 8.
If you skip [3, 4, 5, 6] (sum = 18), you take 1 + 2 + 1 = 4.
If you skip [1, 2, 3, 4] (sum = 10), you take 5 + 6 + 1 = 12  ← best!
*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         int n = cardPoints.size();
        int windowSize = n - k;          
        
        long long total = 0;
        for (int p : cardPoints) total += p;
        
        if (windowSize == 0) return total;
        
        long long windowSum = 0;
        for (int i = 0; i < windowSize; ++i) {
            windowSum += cardPoints[i];
        }
        
        long long minWindowSum = windowSum;
        
        // Slide the window across the array
        for (int i = windowSize; i < n; ++i) {
            windowSum += cardPoints[i];              
            windowSum -= cardPoints[i - windowSize];  
            minWindowSum = min(minWindowSum, windowSum);
        }
        
        return total - minWindowSum;
    }
};