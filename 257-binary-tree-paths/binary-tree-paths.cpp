/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   vector<string> s;
    
    void path(TreeNode* root, string validPath) {
        if (!root) return;

        validPath += to_string(root->val);
        
        if (!root->left && !root->right) {
            s.push_back(validPath);
            return;
        }

        validPath += "->";

        if (root->left) path(root->left, validPath);
        if (root->right) path(root->right, validPath);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
       s.clear();
        path(root, "");
        return s;
    }
};