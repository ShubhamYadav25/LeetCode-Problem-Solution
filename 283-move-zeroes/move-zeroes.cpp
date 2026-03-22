class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;

        // push non-zero
        for (int x : nums) {
            if (x != 0)
                temp.push_back(x);
        }

        // count zeros
        int zeros = nums.size() - temp.size();

        // add zeros
        while (zeros--)
            temp.push_back(0);

        nums = temp;
    }
};