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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // if true, will reverse the elements at level
        bool flag = false;
        
        while(!q.empty()){
            
            vector<int> levelWise;
            
            int n = q.size();
            
            for(int i=0; i< n; i++){
                
                TreeNode* front = q.front();
                q.pop();
                
                levelWise.push_back(front->val);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                
            }
            
            if(flag){
                reverse(levelWise.begin(), levelWise.end());
                ans.push_back(levelWise);
                flag = false; 
            }else {
                ans.push_back(levelWise);
                flag = true;
            }
        }
        return ans;
    }
};