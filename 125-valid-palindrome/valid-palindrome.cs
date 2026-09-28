public class Solution {
  public bool IsPalindrome(string s) {

    string ss = new string(s.Where(char.IsLetterOrDigit).ToArray()).ToLower();

    int i = 0,
    j = ss.Length - 1;
    while (i < j)

    {
      if (ss[i] != ss[j]) return false;

      i++;
      j--;
    }

    return true;

  }
}