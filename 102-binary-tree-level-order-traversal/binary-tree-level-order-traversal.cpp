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
    
    void preorder(TreeNode* node, int level, auto &map){
        if(node == nullptr){
            return;
        }
        
        map[level].push_back(node->val);
        preorder(node->left, level+1, map);
        preorder(node->right, level+1, map);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> map;
        preorder(root, 1, map);
        
            
        for(int i =1; i<=map.size();i++){
            ans.push_back(map[i]);
        }
        
        return ans;
    }
};