class Solution {
public:
    string minWindow(string s, string t) {
        
        // frequency table 
        vector<int> map(128,0);
        
        // add count in freq
        for(auto c: t) map[c]++;
        
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        
        while(end<s.size()){
            
            // if element in map reduce counter 
            // if counter 0 it is valid substrng 
            if(map[s[end++]]-->0) counter--; 
            
            // Now make it invalid from start 
            while(counter==0){ 
                
                // stay with head it will help to find string
                if(end-begin<d)  d=end-(head=begin);
                
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        
        
        return d==INT_MAX? "":s.substr(head, d);
    }
};