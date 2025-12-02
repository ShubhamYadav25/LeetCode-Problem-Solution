class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i =0, j = 0, n = nums.size();
        int maxx = 0;
        while(j < n){
            
            if(nums[j] == 0){
                i = j;
                i++;
            }else {
                maxx = max(j-i+1, maxx);
            }
            j++;
        }

        return maxx;
    }
};