class Solution {
public:
    int longestWPI(vector<int>& hours) {
       int score = 0, max_length = 0;
    unordered_map<int, int> prefix_map; 
    
    for (int i = 0; i < hours.size(); ++i) {
       
        score += (hours[i] > 8) ? 1 : -1;
        

        if (score > 0) {
            max_length = i + 1;
        } 
        else if (prefix_map.count(score - 1)) {
            max_length = max(max_length, i - prefix_map[score - 1]);
        }
        
        if (!prefix_map.count(score)) {
            prefix_map[score] = i;
        }
    }
    
    return max_length; 
       

    }
};