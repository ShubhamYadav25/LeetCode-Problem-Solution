public class Solution {
    public int FindKthLargest(int[] nums, int k) {
         Array.Sort(nums);
         Array.Reverse(nums);

         return nums[k-1];
    }
}