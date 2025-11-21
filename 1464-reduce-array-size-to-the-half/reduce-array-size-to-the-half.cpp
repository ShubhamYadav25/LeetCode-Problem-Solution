class Solution {
public:
    inline std::vector<std::pair<int, int>>
    sorted_by_value_desc(const std::unordered_map<int, int>& m) {
        std::vector<std::pair<int, int>> v(m.begin(), m.end());
        std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        return v;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto i : arr){
            m[i]++;
        }

        auto v = sorted_by_value_desc(m);

        int ans = 0;
        int sum = 0; 
        int n = arr.size();
        int d = n;
        for(auto [a, b] : v){
            cout<<a<<" "<<b<<"\n";
            int x = d - b;
            d = x;
            ans++;
            if(x <= n/2) return ans; 
        }

        return ans;
    }
};