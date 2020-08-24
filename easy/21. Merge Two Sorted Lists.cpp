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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l1Cur = l1;
        ListNode* l2Cur = l2;
        
        if( nullptr == l1 && nullptr == l2 )
            return nullptr;
        
        ListNode* pResultHead = new ListNode;
        ListNode* pReturn = pResultHead;
        
        while( nullptr != l1 || nullptr != l2 ) {
            if( nullptr != l1 && nullptr != l2 ) {
                if( l1->val < l2->val ) {
                    pResultHead->val = l1->val;
                    l1 = l1->next;
                }
                else {
                    pResultHead->val = l2->val;
                    l2 = l2->next;
                }
            }
            else if( nullptr != l1 ) {
                pResultHead->val = l1->val;
                l1 = l1->next;
            }
            else {
                pResultHead->val = l2->val;
                l2 = l2->next;
            }
            
            if( nullptr != l1 || nullptr != l2 ) {
                ListNode* pTemp = new ListNode;
                pResultHead->next = pTemp;
                pResultHead = pTemp;
            }
        }
        
        return pReturn;
    }
};