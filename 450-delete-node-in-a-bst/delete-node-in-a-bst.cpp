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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) return NULL;
        if(root->val == key) return Assign(root);

        TreeNode* dummy = root;

        while(root != NULL){
            
            if(root->val > key){
                // left
                if(root->left != NULL && root->left->val == key){
                    root->left = Assign(root->left);

                } else {
                    root = root->left;
                }

            }else {
                // right
                if(root->right != NULL && root->right->val == key){
                    root->right = Assign(root->right);

                } else {
                    root = root->right;
                }
            }

        }
        return dummy;
    }

    TreeNode* Assign(TreeNode* child){
        if(child ->left == NULL) return child->right;
        else if(child ->right == NULL) return child->left;

        TreeNode* rightsubtree = child->right;
        // if both are there so you can put right subtree to left subtree at right last elemetn
        TreeNode* RightMostChild = GetRightMostElement(child->left);
        RightMostChild->right = rightsubtree;

        return child->left;
    }

    TreeNode* GetRightMostElement(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return GetRightMostElement(root->right);
    }

};