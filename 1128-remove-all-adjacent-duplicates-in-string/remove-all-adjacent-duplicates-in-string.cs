public class Solution {
    public string RemoveDuplicates(string s) {
            char[] result = new char[s.Length];
            int top = -1;

            foreach (char c in s)
            {
                if (top >= 0 && result[top] == c)
                    top--;
                else
                    result[++top] = c;
            }

            return new string(result, 0, top + 1);
    }
}