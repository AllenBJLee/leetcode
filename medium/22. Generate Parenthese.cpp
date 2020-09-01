class Solution {
public:
    void makeParentheses( vector<string>& val, string cur, int nOp, int nCl, int nMax ) {
        if( nMax * 2 == cur.size() ) {
            val.push_back( cur );
        }
        else {
            if( nOp < nMax )
                makeParentheses( val, cur + '(', nOp + 1, nCl, nMax );
            
            if( nCl < nOp )
                makeParentheses( val, cur + ')', nOp, nCl + 1, nMax );
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        makeParentheses( result, "", 0, 0, n );
        
        return result;
    }
};