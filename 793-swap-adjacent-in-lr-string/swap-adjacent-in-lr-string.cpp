class Solution {
public:
    bool canTransform(string s, string t) {
		vector<pair<char, int>> v1, v2;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != 'X')v1.push_back({s[i], i});
			if (t[i] != 'X')v2.push_back({t[i], i});
		}
		if (v1.size() != v2.size()) return false;
		else {
			for (int i = 0; i < v1.size(); ++i) {
				if (v1[i].first == 'L' && v2[i].first == 'L') {
					if (v1[i].second < v2[i].second) return false;
				}
				else if (v1[i].first == 'R' && v2[i].first == 'R') {
					if (v1[i].second > v2[i].second) return false;
				}
				else return false;
			}
		}
		return true;
	}
};