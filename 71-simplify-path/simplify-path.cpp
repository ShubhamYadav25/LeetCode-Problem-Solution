class Solution {
public:
    string simplifyPath(string path) {
         vector<string> stack; 
        stringstream ss(path);
        string piece;
        
        while (getline(ss, piece, '/')) {
            if (piece == "" || piece == ".") {
                continue;
            } 
            else if (piece == "..") {
                if (!stack.empty()) stack.pop_back();
            } 
            else {
                stack.push_back(piece);
            }
        }
        
        if (stack.empty()) return "/"; 
        
        string result = "";
        for (string &dir : stack) {
            result += "/" + dir;
        }
        
        return result;
    }
};