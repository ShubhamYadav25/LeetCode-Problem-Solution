public class Solution {
    /**
    Dutch National Flag Algorithm
    Three Pointers
    | Pointer | Role                                          |
    | ------- | --------------------------------------------- |
    | `left`  | Everything **before** this index is `0` (red) |
    | `right` | Everything **after** this index is `2` (blue) |
    | `i`     | Current element being examined                |

    Algorithm
        Initialize left = 0, right = n - 1, i = 0
        While i <= right:
        If nums[i] == 0: swap with nums[left], increment both left and i
        If nums[i] == 1: just increment i
        If nums[i] == 2: swap with nums[right], decrement right only (don't increment i — the swapped-in element needs inspection)

    */
    public void SortColors(int[] nums) {
        int left = 0;
        int right = nums.Length - 1;
        int i = 0;

        while (i <= right) {
            if (nums[i] == 0) {
                // Swap current with left boundary, expand red zone
                (nums[i], nums[left]) = (nums[left], nums[i]);
                left++;
                i++;
            }
            else if (nums[i] == 1) {
                // White stays in the middle, just move on
                i++;
            }
            else { // nums[i] == 2
                // Swap current with right boundary, expand blue zone
                (nums[i], nums[right]) = (nums[right], nums[i]);
                right--;
                // Don't increment i — need to check the swapped element
            }
        }
    }
}