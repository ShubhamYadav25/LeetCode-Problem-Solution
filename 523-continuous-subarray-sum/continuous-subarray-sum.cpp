class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int N) {
        
        // {reminder, index }
        unordered_map<int , int> m;
        m[0] = -1;

        int prefixSum=0;
        int k = nums.size();
        int j =0;
        while(j < k){
            prefixSum += nums[j];
            int remindar = prefixSum % N;
            
            if(m.find(remindar) != m.end() ){
                if ((j - m[remindar]) >=2) return true;
            } else {
                m[remindar] = j;
            }
            
            j++;
        }

    return false;
    }
};