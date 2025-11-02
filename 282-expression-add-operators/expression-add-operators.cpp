class Solution {
public:
    // pos = index
    // curVal = value calculated so far
    // last =last vlue on which operation performed
    // expr = path 
    void dfs(string& num, int target, int pos, long long curVal, long long last,
             string expr, vector<string>& res) {

        // Base case: reached end of string
        if (pos == num.size()) {
            if (curVal == target)
                res.push_back(expr);
            return;
        }

        // Try all possible splits from current pos
        for (int i = pos; i < num.size(); i++) {
            // Skip numbers with leading zero
            if (i != pos && num[pos] == '0')
                break;

            string part = num.substr(pos, i - pos + 1);
            long long val = stoll(part);

            if (pos == 0) {
                // First number: no operator before it
                dfs(num, target, i + 1, val, val, part, res);
            } else {
                // Try adding '+'
                dfs(num, target, i + 1, curVal + val, val, expr + "+" + part,
                    res);

                // Try adding '-'
                dfs(num, target, i + 1, curVal - val, -val, expr + "-" + part,
                    res);

                // Try adding '*'
                dfs(num, target, i + 1, curVal - last + last * val, last * val,
                    expr + "*" + part, res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty())
            return res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
};