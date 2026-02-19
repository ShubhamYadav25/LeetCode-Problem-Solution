class Solution {
public:
    string result;
    int count = 0;

    void backtrack(vector<int>& nums, vector<bool>& used, string& current,
                   int n, int k) {

        if (current.size() == n) {
            count++;
            if (count == k) {
                result = current;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;

            used[i] = true;
            current += to_string(nums[i]);

            backtrack(nums, used, current, n, k);

            // Stop early if found
            if (!result.empty())
                return;

            current.pop_back();
            used[i] = false;
        }
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        vector<bool> used(n, false);
        string current = "";

        backtrack(nums, used, current, n, k);

        return result;
    }
};