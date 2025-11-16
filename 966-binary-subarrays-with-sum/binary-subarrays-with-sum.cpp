class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // prefixCount[x] tells how many times prefix sum value x has appeared so far.
        unordered_map<int, int> prefixCount;

        // Before scanning array, we assume prefix sum = 0 has occurred once
        // at imaginary index L-1 = -1 (used for subarrays starting at index 0).
        prefixCount[0] = 1;

        int prefixSum_R = 0;   // P[R] = prefix sum from index 0 to R
        int totalSubarrays = 0;

        // Move R from 0 to n-1 (right boundary of subarray)
        for(int R = 0; R < nums.size(); R++) {

            // Update prefix sum including nums[R]
            prefixSum_R += nums[R];

            // We want sum(L..R) = goal
            // => prefix[R] - prefix[L-1] = goal
            // => prefix[L-1] = prefix[R] - goal
            int neededPrefix_Lminus1 = prefixSum_R - goal;

            // Check how many valid prefix[L-1] existed before this position
            if(prefixCount.count(neededPrefix_Lminus1)) {
                // Every matching prefix gives ONE valid (L..R) subarray.
                totalSubarrays += prefixCount[neededPrefix_Lminus1];
            }

            // Record that prefixSum_R is now seen once more
            // so future indices can treat R as their (L-1)
            prefixCount[prefixSum_R]++;
        }

        return totalSubarrays;
    }
};
