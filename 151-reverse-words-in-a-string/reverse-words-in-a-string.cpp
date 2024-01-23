class Solution {
public:
    string reverseWords(string str) {
     
        string output = "";
        stack<string> reveredString;

        istringstream stringStream(str);
        
        string tokenizeString;
        
        while(stringStream >> tokenizeString){
            if(tokenizeString != ""){
                reveredString.push(tokenizeString);            
            }
        }
    
        while(!reveredString.empty()){
            output += reveredString.top();
            reveredString.pop();
            if(!reveredString.empty()){
                output+=" ";
            }
        }
        return output;
    }
};