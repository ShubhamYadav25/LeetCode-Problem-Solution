class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int left =0, n = nums.size(), maxLen = -1;
        int currentSum = 0;

        // instead of removing element we convert this question to 
        // find longest contiguous subarray whose sum = totalSum - x
        int target = totalSum - x;

        for (int right = 0; right < nums.size(); ++right) {

            currentSum += nums[right];

            // Shrink window from the left if currentSum exceeds target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                ++left;
            }

            // Check if we found a subarray with the target sum
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : nums.size() - maxLen;

    }
};