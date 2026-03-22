class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        // move non-zero
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        // fill zeros
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};