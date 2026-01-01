class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int i = 0, ans = 0;

        for (int j = 0; j < nums.size(); j++) {

            // Maintain max deque
            while (!maxD.empty() && nums[j] > maxD.back())
                maxD.pop_back();
            maxD.push_back(nums[j]);

            // Maintain min deque
            while (!minD.empty() && nums[j] < minD.back())
                minD.pop_back();
            minD.push_back(nums[j]);

            // Shrink window if invalid
            while (maxD.front() - minD.front() > limit) {
                if (nums[i] == maxD.front()) maxD.pop_front();
                if (nums[i] == minD.front()) minD.pop_front();
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
