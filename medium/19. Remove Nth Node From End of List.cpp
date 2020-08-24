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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nCount = 0;
        
        ListNode* pCur = head;
        
        while( nullptr != pCur ) {
            ++nCount;
            pCur = pCur->next;
        }
        
        int nFoundNode = nCount - n;
        
        if( nFoundNode < 0 ) {
            return nullptr;
        }
        
        pCur = head;
        
        for( int nIndex = 0; nIndex < nFoundNode - 1; ++nIndex ) {
            pCur = pCur->next;
        }
        
        if( 0 == nFoundNode ) {
            head = head->next;
        }
        else if( nullptr != pCur ) {
            ListNode* pTemp = pCur->next;
            
            if( nullptr == pTemp ) {
                head = nullptr;
            }
            else {
                pCur->next = pTemp->next;
            }
        }
        
        return head;
    }
};