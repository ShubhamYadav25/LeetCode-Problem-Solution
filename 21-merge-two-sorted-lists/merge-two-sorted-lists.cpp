/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* newList = dummy;  
        ListNode* tList1 = list1;
        ListNode* tList2 = list2;

        while(tList1 != NULL && tList2 != NULL){
            if( tList1->val < tList2->val  ){
                newList->next = tList1;
                tList1 = tList1->next;
            }else {
                newList->next = tList2;
                tList2 = tList2->next;
            }

             newList = newList->next;
        }

        if(tList1 != NULL){
            newList->next = tList1;
        }
        if(tList2 != NULL){
            newList->next = tList2;
        }

        return dummy->next;
    }
};