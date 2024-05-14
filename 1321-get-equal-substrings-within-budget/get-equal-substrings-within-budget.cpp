class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
     
        int i=0, j=0, sum=0;
        
        int res = 0;
        
        while(j < s.length()){
            
            sum += abs (s[j]-t[j]);
            while(sum > maxCost){
                sum -= abs (s[i]-t[i]);
                i++;
            }
            j++;
            res = max(res, j-i);

        }
        
        
        return res;
        
    }
};