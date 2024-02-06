class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int maxAltitude = 0;
        int prefixSum =0;
        for(auto i : gain){
            prefixSum += i;
            maxAltitude = max(maxAltitude, prefixSum);
        }
        
        return maxAltitude;
    }
};