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
    ListNode* middleNode(ListNode* head) {
        vector< ListNode* > vecNode;
        
        vecNode.reserve(100);
        
        ListNode* pCurrentNode = head;
        
        vecNode.push_back(pCurrentNode);
        
        while( nullptr != pCurrentNode->next ) {
            pCurrentNode = pCurrentNode->next;
            vecNode.push_back(pCurrentNode);
        }
        
        int nMidIdx = 0;
        
        printf( "size:%d idx:%d\n", vecNode.size(), vecNode.size()/2 );
        
        if( 1 < vecNode.size() ) {
            nMidIdx = (vecNode.size() / 2);// + (vecNode.size()%2);
        }
        
        return( vecNode[nMidIdx] );
    }
};