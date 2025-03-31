class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_mod_count;
    prefix_mod_count[0] = 1; 
    int prefix_sum = 0, count = 0;

    for (int num : nums) {
        prefix_sum += num;
        int mod = prefix_sum % k;

        if (mod < 0) 
            mod += k;

        count += prefix_mod_count[mod];

        prefix_mod_count[mod]++;
    }
    
    return count;
    }
};