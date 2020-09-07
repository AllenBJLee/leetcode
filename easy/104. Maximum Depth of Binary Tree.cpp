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
    int dfs( int nDepth, TreeNode* pCur ) {
        if( nullptr == pCur )
            return nDepth;
        
        ++nDepth;
        
        int nLeftDepth = nDepth;
        int nRightDepth = nDepth;
        
        if( nullptr != pCur->left ) {
            nLeftDepth = dfs( nLeftDepth, pCur->left );
        }
        
        if( nullptr != pCur->right ) {
            nRightDepth = dfs( nRightDepth, pCur->right );
        }
        
        return( max( nLeftDepth, nRightDepth ) );
    }
    
    int maxDepth(TreeNode* root) {
        return( dfs( 0, root ) );
    }
};