class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, zero = 0, ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0)
                zero++;

            while (zero > k) {
                if (nums[i] == 0)
                    zero--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};