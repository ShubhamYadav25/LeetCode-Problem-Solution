class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int factorial = 1;

        // Compute (n-1)! => block size 1-6, 7-12 ....
        for (int i = 1; i < n; i++)
            factorial *= i;

        // Store numbers 1 to n
        for (int i = 1; i <= n; i++)
            numbers.push_back(i);

        k--; // convert to 0-based indexing

        string result = "";

        while (n > 0) {
            // to check pos as index where k lies in which blocks 1-6 or 7-12 or ...  
            // 1–6 → start with 1
            // 7–12 → start with 2
            // 13–18 → start with 3
            // 19–24 → start with 4
            int index = k / factorial;
            result += to_string(numbers[index]);

            // now remove that num and check for other like  2 [1 3 4]
            numbers.erase(numbers.begin() + index);
            
            // instead of substrac 9 - 6 = 3 we can do below
            k = k % factorial;
            n--;

            if (n > 0)
                factorial /= n;
        }

        return result;
    }
};