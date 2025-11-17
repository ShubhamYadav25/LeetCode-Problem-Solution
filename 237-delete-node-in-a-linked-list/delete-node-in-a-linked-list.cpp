/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;

        while(node->next){
            prev->val = node->next->val;
            node->next->val = node->val;
            node = node->next;
            if(node->next != nullptr) prev = node;
        }

        prev->next = nullptr;
        node = prev;
    }
};