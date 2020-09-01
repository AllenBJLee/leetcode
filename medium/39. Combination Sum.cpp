class Solution {
public:
    
    void combi(
        vector<vector<int>>& result,
        vector<int>& cand,
        vector<int>& temp,
        int nIdx,
        int nTarget
              ) {
        
        if( 0 == nTarget ) {
            result.push_back( temp );
            
            return ;
        }
        
        for( int i = nIdx; i < cand.size(); ++i ) {
            if( cand[i] > nTarget )
                break;
            
            temp.push_back( cand[i] );
            combi( result, cand, temp, i, nTarget - cand[i] );
            temp.pop_back( );
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        
        vector<vector<int>> result;
        vector<int> temp;
        combi( result, candidates, temp, 0, target );
        
        
        return result;
    }
};