public class Solution {
    public bool ContainsDuplicate(int[] nums) {
         return nums.GroupBy(x => x)
               .Any(g => g.Count() > 1);
    }
}