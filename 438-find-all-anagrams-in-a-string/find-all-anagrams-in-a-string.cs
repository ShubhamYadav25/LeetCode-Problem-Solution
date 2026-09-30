public class Solution {
    public IList<int> FindAnagrams(string s, string p) {

        // freq with lenth 26 and intial value 0
        var pFreq = new int[26];
        var sFreq = new int[26];

        foreach(var x in p){
            pFreq[x - 'a']++;
        }

        int i =0, j =0, n = s.Length;

        var ans = new List<int>();

        while(j < n){
            
            sFreq[s[j] - 'a']++;

            if(j-i+1 == p.Length){
                
                if(sFreq.SequenceEqual(pFreq)) ans.Add(i); 
                
                sFreq[s[i] - 'a']--;
                i++;
            }
            j++;

        }   

        return ans;
        
    }
}