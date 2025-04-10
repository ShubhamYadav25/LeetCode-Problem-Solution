class Solution {
public:
/**
 More optimized to my prev soln
*/
    vector<int> finalPrices(vector<int>& nums) {
        
    int n = nums.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] <= nums[st.top()]) {
            nums[st.top()] -= nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    return nums;
   
    }
};