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
    int ans = 0;
    string pathSum = "";
    void SumPath(TreeNode* root){
        if (!root) return;

        pathSum += std::to_string(root->val);

        // If it's a leaf node, add the number to the answer
        if (!root->left && !root->right) {
            ans += stoi(pathSum);
        } else {
            SumPath(root->left);
            SumPath(root->right);
        }

        // Backtrack: Remove the last digit for correct path
        pathSum.pop_back();

    }

    int sumNumbers(TreeNode* root) {
        SumPath(root);
        return ans;
    }
};