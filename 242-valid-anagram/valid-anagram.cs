public class Solution {
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length) return false;

        var arr = s.ToCharArray();
        Array.Sort(arr);
        var s1 = new string(arr);
        
        var arr1 = t.ToCharArray();
        Array.Sort(arr1);
        var t1 = new string(arr1);

        return s1 == t1;
        
    }
}