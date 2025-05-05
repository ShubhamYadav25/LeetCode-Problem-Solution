/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
         // Base case: if root is null or root is one of the nodes
    if (root == nullptr || root->val == n1->val || root->val == n2->val) {
        return root;
    }

    
    TreeNode* leftLCA = lowestCommonAncestor(root->left, n1, n2);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, n1, n2);

    if (leftLCA && rightLCA) {
        return root;
    }

     return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};