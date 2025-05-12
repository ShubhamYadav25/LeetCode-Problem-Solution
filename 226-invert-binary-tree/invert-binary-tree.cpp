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
    void swap(TreeNode* root){
        
        // if it is null
        if(!root) return;

        // otherwise goes to bottom
        swap(root->left);
        swap(root->right);

        // if it is node with its left or right (can be null) swap them
        // Swap left and right child
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

    }
    TreeNode* invertTree(TreeNode* root) {
        swap(root);
        return root;
    }
};