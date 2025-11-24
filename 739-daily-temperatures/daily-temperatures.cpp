class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<int> s; // index
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            
            // next greater
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                result[s.top()] = i - s.top();
                s.pop();
            }
            
            s.push(i);
        }
        
        return result;
    }
};