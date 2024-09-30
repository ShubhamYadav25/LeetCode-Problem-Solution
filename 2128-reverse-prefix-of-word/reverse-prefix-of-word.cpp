class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int j = word.length()-1;
        
        stack<char> rev;
        
        while(i<=j){
            rev.push(word[i]);
            if(ch == word[i]){
                break;   
            }
            
            
        
            i++;
        }
        
        string s1 = "";

        
        while(!rev.empty()){
            s1 += (rev.top());
            rev.pop();
        }
        
    
        return (i>j)? word: s1+word.substr(i+1);
        
        
    }
};