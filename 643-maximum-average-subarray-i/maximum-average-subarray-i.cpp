class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int i =0, j=0;
        int n = nums.size();
                
        int sum = 0;
        double ans = -DBL_MAX;
        
        while(j < n && i< n){
           
            sum += nums[j];
            
            if(j -i +1 == k){
                double avg = double(sum) / double(k);
                
                ans = max(ans, avg);
                
                sum -= nums[i];
                
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};