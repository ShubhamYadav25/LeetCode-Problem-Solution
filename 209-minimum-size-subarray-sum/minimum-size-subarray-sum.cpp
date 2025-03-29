class Solution {
public:
    int minSubArrayLen(int K, vector<int>& arr) {
        int left = 0, prefixSum = 0, minLength = INT_MAX;

    for (int right = 0; right < arr.size(); right++) {
        prefixSum += arr[right];

        while (prefixSum >= K) {  
            minLength = min(minLength, right - left + 1);
            prefixSum -= arr[left]; 
            left++;
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
    }
};