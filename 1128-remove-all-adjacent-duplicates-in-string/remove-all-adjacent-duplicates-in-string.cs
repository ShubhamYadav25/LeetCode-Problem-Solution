public class Solution {
    public string RemoveDuplicates(string s) {
        
        Stack<char> st = new();

        foreach(var i in s){

             // TryPeek returns false if empty, or checks the value if elements exist
           if(st.TryPeek(out var top) && top == i){
                st.Pop();
            }
            else{
                st.Push(i);
            }
        }

        return string.Join("", st.Reverse());

    }
}