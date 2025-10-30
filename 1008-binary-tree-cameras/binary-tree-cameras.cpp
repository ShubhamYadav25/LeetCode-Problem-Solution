/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // 0 = NEED, 1 = COVERED, 2 = CAM
    int cams = 0;

    int dfs(TreeNode* node) {

        if (!node)
            return 1; // null is COVERED

        int L = dfs(node->left);
        int R = dfs(node->right);

        if (L == 0 || R == 0) { // a child needs coverage
            cams++;
            return 2; // place camera here
        }
        if (L == 2 || R == 2) { // a child has a camera
            return 1;           // this node is covered
        }
        return 0; // this node needs coverage
    }
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cams++; // root still needs a camera
        return cams;
    }
};