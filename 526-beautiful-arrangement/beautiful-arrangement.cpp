class Solution {
public:
int count = 0;

    void backtrack(int pos, int n, vector<bool>& visited) {
        if (pos > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                backtrack(pos + 1, n, visited);
                visited[i] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool> visited(n + 1, false);
        backtrack(1, n, visited);
        return count;
    }
};