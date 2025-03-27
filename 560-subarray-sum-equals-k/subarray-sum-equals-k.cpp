class Solution {
public:
    int subarraySum(vector<int>& arr, int K) {
        unordered_map<int, int> prefixCount;  
        prefixCount[0] = 1;  
    
    int prefixSum = 0, count = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i]; 

        int x = prefixSum - K;

        if (prefixCount.find(x) != prefixCount.end()) {
            count += prefixCount[x]; 
        }

        prefixCount[prefixSum]++;
    }

    return count;
    }
};