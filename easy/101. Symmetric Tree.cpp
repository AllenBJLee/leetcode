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
    bool dfs( TreeNode* t1, TreeNode* t2 ) {
        if( nullptr == t1 && nullptr == t2 ) {
            return true;
        }
        
        if( nullptr == t1 || nullptr == t2 ) {
            return false;
        }
        
        if( t1->val != t2->val ) {
            return false;
        }
        
        bool bResult = ( t1->val == t2->val ) &&
                    ( dfs( t1->left, t2->right ) ) &&
                    ( dfs( t1->right, t2->left ) );
        
        return bResult;
    }
    
    bool isSymmetric(TreeNode* root) {
        if( nullptr == root )
            return true;
        
        return dfs( root, root );
    }
};