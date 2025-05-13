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

    void SumPath(TreeNode* root, int pathSum) {
        if (!root) return;

        pathSum = pathSum * 10 + root->val;

        if (!root->left && !root->right) {
            ans += pathSum;
            return;
        }

        SumPath(root->left, pathSum);
        SumPath(root->right, pathSum);
    }

    int sumNumbers(TreeNode* root) {
          SumPath(root, 0);
         return ans;
    }
};