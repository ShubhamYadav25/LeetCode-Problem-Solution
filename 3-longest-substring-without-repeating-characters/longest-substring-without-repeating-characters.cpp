class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i =0,j=0;
        unordered_map<char, int> map;
        int counter =0;
        int d = INT_MIN;
        if(!s.length()) return 0;
        while(j< s.length()){
            
            // if char s[j] not present in map increase counter
            if(map[s[j]]++ == 0) counter ++;
            
            while(map[s[j]]>1) if(map[s[i++]]-->1) counter--;
            j++;
            d = max(d, j-i);
        }
        
        return d;
        
    }
};