class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, cnt[26] = {}, ans = 0, N = s.size();
        while (j < N) {
            cnt[s[j++] - 'A']++;
            while (j - i - *max_element(cnt, cnt + 26) > k) cnt[s[i++] - 'A']--;
            ans = max(ans, j - i);
        }
        return ans;
    }
};