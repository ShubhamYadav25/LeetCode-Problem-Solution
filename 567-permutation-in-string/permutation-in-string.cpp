class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.length();
        int n2 = s2.length();

        // create window for s1 and s2
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (auto x : s1) {
            v1[x - 'a'] += 1;
        }
        
        int i = 0, j = 0;
        while (j < n2) {
            v2[s2[j] - 'a'] += 1;

            if (j - i + 1 == n1) {
                if (v1 == v2)
                    return true;

                v2[s2[i] - 'a'] -= 1;

                i++;
            }

            j++;
        }

        return false;
    }
};