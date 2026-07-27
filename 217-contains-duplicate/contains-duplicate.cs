public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        
        HashSet<int> h = new(nums);

        return h.Count != nums.Length;
        
    }
}