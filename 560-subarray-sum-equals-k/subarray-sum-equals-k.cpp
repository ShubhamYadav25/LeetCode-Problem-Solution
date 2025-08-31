class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;  // empty prefix sum
        int sum = 0;
        int c = 0;

        for(int num : nums) {
            sum += num;

            // if we find same sum it mean it is a valid subarray
            if(m.find(sum - k) != m.end()) {
                c += m[sum - k];
            }

            // keeping sum occurence why
            // If m[S] = 2, there are two different starting points that give us subarray sum = k.
            // To count valid subarray
            m[sum]++;
        }
        return c;
    }
};