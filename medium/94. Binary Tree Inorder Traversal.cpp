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
    
    void trace( vector<int>& result, TreeNode* cur ) {
        if( cur->left ) {
            trace( result, cur->left );
        }
        
        result.push_back( cur->val );
        
        if( cur->right ) {
            trace( result, cur->right );
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if( nullptr == root )
            return result;
        
        trace( result, root );
        
        return result;
    }
};