class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v1(26, 0);
        vector<int> v;

        for(auto i: p){
            v1[i - 'a']++;
        }
        // maintaining a array
        vector<int> v2(26,0);

        int i = 0, j=0, n = s.length();
        while( j < n ){
            v2[s[j]- 'a']++;
            if(j - i + 1 == p.length()){
                if(v1 == v2) v.push_back(i);
                v2[s[i] -'a']--;
                i++;
            }
            j++;
        }

        return v;
    }
};