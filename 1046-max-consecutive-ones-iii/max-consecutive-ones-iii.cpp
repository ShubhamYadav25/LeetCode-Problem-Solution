class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i=0, j=0, n = nums.size();

        int ans = -1;
        int zero =0;
        while(j < n){
            if(nums[j] ==0){
                zero++;
            }

            if(zero > k){
                while(zero > k){
                    if(nums[i] == 0){
                        zero--;
                        
                    }
                    i++;
                }
            }
            
            ans = max(j-i+1, ans);
            j++;
        }

        return ans;

    }
};