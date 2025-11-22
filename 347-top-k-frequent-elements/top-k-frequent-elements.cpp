class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // count frequencies
        for (int x : nums) {
            freq[x]++;
        }

        // max heap of pair(freq, number)
        priority_queue<pair<int, int>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
        }

        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};