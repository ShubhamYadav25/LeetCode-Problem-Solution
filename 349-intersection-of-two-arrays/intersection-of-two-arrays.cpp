class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        for(auto i : nums1){
            if(find(nums2.begin(), nums2.end(), i) != nums2.end() && find(v.begin(), v.end(), i) == v.end() ){
                v.push_back(i);
            }
        }

        return v;
    }
};