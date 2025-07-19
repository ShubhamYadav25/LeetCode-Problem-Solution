class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modCount;
        modCount[0] = 1; 

        int prefixSum = 0;
        int result = 0;

        for (int num : nums) {
            prefixSum += num;

            // Always be non-negative
            int mod = prefixSum % k;
            if (mod < 0) mod += k;

            // If this mod has been seen, add its count to result
            if (modCount.find(mod) != modCount.end()) {
                result += modCount[mod];
            }

            modCount[mod]++;
        }

        return result;
    }
};