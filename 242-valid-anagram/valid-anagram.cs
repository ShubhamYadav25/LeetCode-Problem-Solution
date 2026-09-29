public class Solution {
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length) return false;
        var dict = new Dictionary<char, int>();

        foreach(char i in  s) {
            if(dict.ContainsKey(i)){
                dict[i]++;
            }else
            {
                dict[i] = 1;
            }
        }

        foreach(char i in t){
            
            if(!dict.ContainsKey(i)){
                return false;
            }
            
            dict[i]--;
            
            if(dict[i] < 0) return false;
        }

        return true;
    }
}