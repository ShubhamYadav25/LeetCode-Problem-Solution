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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root)
            return {};
        if (!target)
            return {};
        if (K == 0)
            return {target->val};

        // 1) Build parent pointers
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParents(root, nullptr, parent);

        // 2) BFS from target
        vector<int> result;
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q; // node, distance from target
        q.push({target, 0});
        visited.insert(target);

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (dist == K) {
                // collect this node and all other nodes at same distance in
                // queue (and skip expanding them)
                result.push_back(node->val);
                // nodes already in queue may be same distance; collect them too
                while (!q.empty()) {
                    auto p = q.front();
                    if (p.second == K) {
                        result.push_back(p.first->val);
                        q.pop();
                    } else
                        break;
                }
                break;
            }
            // expand neighbors: left, right, parent
            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                q.push({node->left, dist + 1});
            }
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                q.push({node->right, dist + 1});
            }
            auto it = parent.find(node);
            if (it != parent.end() && it->second &&
                !visited.count(it->second)) {
                visited.insert(it->second);
                q.push({it->second, dist + 1});
            }
        }
        return result;
    }

private:
    void buildParents(TreeNode* node, TreeNode* par,
                      unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node)
            return;
        parent[node] = par;
        buildParents(node->left, node, parent);
        buildParents(node->right, node, parent);
    }
};