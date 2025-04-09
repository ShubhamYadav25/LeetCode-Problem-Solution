class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; 

        for (int i = 0; i < 2 * n; ++i) {
            int currIndex = i % n;

            while (!st.empty() && nums[currIndex] > nums[st.top()]) {
                res[st.top()] = nums[currIndex];
                st.pop();
            }

            // Only push index in the first round
            if (i < n) {
                st.push(currIndex);
            }
        }

        return res;
    }
};