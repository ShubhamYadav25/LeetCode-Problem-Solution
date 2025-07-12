class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        int intialSatisfied = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                intialSatisfied += customers[i];
            }
        }

        // now we are calculation extra satisfied by secret technique with window size
        // minutes 
        int extra = 0; 
        int maxExtra = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }

            // remove if (i - minutes) is not in current window boundry
            if (i >= minutes) {
                if (grumpy[i - minutes] == 1) {
                    extra -= customers[i - minutes];
                }
            }

            maxExtra = max(maxExtra, extra);
        }

        return intialSatisfied + maxExtra;
    }
};