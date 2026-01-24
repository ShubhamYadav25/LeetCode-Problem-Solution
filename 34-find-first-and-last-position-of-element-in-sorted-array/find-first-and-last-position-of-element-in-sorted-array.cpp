class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int i = 0, j = nums.size() - 1;
        int ans = -1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (findFirst)
                    j = mid - 1; // move left
                else
                    i = mid + 1; // move right
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};

        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);

        return {first, last};
    }
};
