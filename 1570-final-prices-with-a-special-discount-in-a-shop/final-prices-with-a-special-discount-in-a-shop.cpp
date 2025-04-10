class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] <= nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    
    vector<int> res = nums;
    for(int i = 0; i < n; i++){
        if(result[i] == -1) continue;
        res[i] = nums[i] - result[i];
    }

    return res;

    }
};