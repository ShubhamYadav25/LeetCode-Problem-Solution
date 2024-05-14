class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
     
        int i=0, j=0, sum=0;
        
        int res = 0;
        
        while(j < s.length()){
            
            // add ascii difference
            sum += abs (s[j]-t[j]);
            
            // invalid window when sum > maxCost
            // then decrease it to valid window
            while(sum > maxCost){
                sum -= abs (s[i]-t[i]);
                i++;
            }
            
            // update the counter to process further chars in string s
            j++;
            
            // update the result
            res = max(res, j-i);

        }
        
        
        return res;
        
    }
};