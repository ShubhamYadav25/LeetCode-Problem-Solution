class Solution {
public:
    // if nums[mid] > nums[right] it mean min element in right space
    // if equal then they are duplicate
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else if (nums[mid] < nums[right])
            right = mid;
        else
            right--;  // handle duplicates
            // because removing one duplicate doesn’t change the answer so you can remove any
    }
    return nums[left]; // when loop exit, the left = right so u can return any
    }
};