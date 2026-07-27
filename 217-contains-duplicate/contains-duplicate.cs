public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        var d = new Dictionary<int, int>();
        
        for(var i = 0; i < nums.Length; i++){
             if(d.ContainsKey(nums[i])){
                 return true;
             }

             d.Add(nums[i], 0);
        }
        
        return false;
        
    }
}