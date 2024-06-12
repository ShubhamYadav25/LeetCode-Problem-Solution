class Solution {
public:
    
    bool isTransferable(int capacity, vector<int>& weights, int days) {
        
        // days need to transfer all items with limit of {capacity}
        int daysTaken = 1;
        
        // sum use for adding weights in one go
        int sum =0;
        
        for(int i =0; i< weights.size(); i++){
            
            sum += weights[i];
            
            // check sum is greater than the assumed capacity then daysTaken increase 
            // and new days start so sum start from current weight
            
            if(sum > capacity) {
                daysTaken ++;
                
                sum = weights[i];
            }
        }
        
        // if daysTaken is greater than provided days so it is not acceptable
        if(daysTaken <= days) {
            return true;
        }
        
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        // max will be sum of all
        int maxCapacity=0;
        
        int n = weights.size();
        
        for(int i = 0; i < n; i++)
            maxCapacity += weights[i];
        
        int l = *max_element(weights.begin(), weights.end()), r = maxCapacity;
        int ans;
        
        while(l <= r) {
            
            // asumed capacity 
            int mid = l + (r - l) /2;
            
            // check in this capacity (mid) can we transfer total load in days
            // if yes then we go for least capacity
            
            if(isTransferable(mid, weights, days)){
                ans = mid;
                r = mid-1;    
            }else {
                l = mid +1 ;
            }
        }
        return ans;
    }
};