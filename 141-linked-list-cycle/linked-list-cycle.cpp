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
    bool hasCycle(ListNode *head) {
        
        while(head != NULL){
            int val = head->val;
            if(val == INT_MIN) return true;
            head->val = INT_MIN;
            head = head->next;
        }
        return false;
    }
};