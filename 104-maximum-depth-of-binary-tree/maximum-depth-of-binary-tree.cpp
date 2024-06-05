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
    int maxDepth(TreeNode* root) {
         int d = INT_MIN;
        
        queue<TreeNode*>q;
     
        if(root==NULL) return 0;
        q.push(root);
        int z = 1;
        
        while(q.empty()!=true)
        {   vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            {   TreeNode* t=q.front();q.pop();
                v.push_back(t->val);
                if(!t->left && !t->right){
                    d = max(z, d);
                }
                if(t->left)
                { 
                    
                    q.push(t->left);
                };
                if(t->right){
                   
                    q.push(t->right);
                };
               
            }
          
             z++;
        }
        return d;
    }
};