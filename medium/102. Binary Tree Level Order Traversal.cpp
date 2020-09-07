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
    struct TempData {
        TreeNode* pCur{ nullptr };
        int nDepth{ 0 };
    };
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if( nullptr == root )
            return result;
        
        vector<int> temp;
        
        queue<TempData> q;
        
        TempData data{ root, 1 };
        q.push(data);
        
        int nCurDepth = 1;
        
        while( false == q.empty() ) {
            data = q.front();
            
            if( nullptr != data.pCur->left ) {
                q.push( TempData{ data.pCur->left, data.nDepth+1 } );
            }
            
            if( nullptr != data.pCur->right ) {
                q.push( TempData{ data.pCur->right, data.nDepth+1 } );
            }
            
            if( nCurDepth == data.nDepth ) {
                temp.push_back( data.pCur->val );
            }
            else {
                result.push_back( temp );
                temp.clear();
                nCurDepth = data.nDepth;
                temp.push_back( data.pCur->val );
            }
            
            q.pop();
        }
        
        if( false == temp.empty() ) {
            result.push_back(temp);
        }
        
        return result;
    }
    
};