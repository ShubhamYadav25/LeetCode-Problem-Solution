public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        
        nums.Sort();

        for(var i =0; i < nums.Length - 1; i++){
            if( nums[i] == nums[i+1]) return true;
        }

        return false;
    }
}