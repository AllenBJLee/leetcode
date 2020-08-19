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
    bool IsNext( ListNode** p ) {
        if( nullptr != *p ) {
            *p = (*p)->next;
            
            if( nullptr != *p ) {
                return true;
            }
        }
        return false;
    }
    
    bool Calc( ListNode** l1, ListNode** l2, ListNode** pResult ) {       
        int nL1 = ( nullptr == *l1 ? 0 : (*l1)->val );
        int nL2 = ( nullptr == *l2 ? 0 : (*l2)->val );
        
        int nRemain = 0;
        
        if( 10 <= nL1 + nL2 ) {
            (*pResult)->val = (nL1 + nL2) % 10;
            
            nRemain = (nL1 + nL2) / 10;
        }
        else {
            (*pResult)->val = (nL1 + nL2);
        }
        
        bool bResult = IsNext( l1 ) | IsNext( l2 );
        
        if( true == bResult ) {
            ListNode* pTemp = ( nullptr != *l1 ? *l1 : *l2 );
            
            pTemp->val += nRemain;
            
            pTemp = new ListNode;
        
            (*pResult)->next = pTemp;
            (*pResult) = pTemp;
        }
        else if( nRemain > 0 ) {
            ListNode* pTemp = new ListNode;
            
            (*pResult)->next = pTemp;
            pTemp->val = nRemain;
        }

        
        return bResult;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode;
        
        ListNode* pL1Cur = l1;
        ListNode* pL2Cur = l2;
        
        ListNode* pCur = pHead;
        
        bool bResult = true;
        do {
            bResult = Calc( &pL1Cur, &pL2Cur, &pCur );
        } while( true == bResult );
        
        return pHead;
    }
    
    
};