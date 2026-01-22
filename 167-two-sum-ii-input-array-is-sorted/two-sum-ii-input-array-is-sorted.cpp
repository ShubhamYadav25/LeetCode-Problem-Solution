class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int need = target - numbers[i];
            int l = i + 1, r = n - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (numbers[mid] == need)
                    return {i + 1, mid + 1};
                else if (numbers[mid] < need)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return {};
    }
};