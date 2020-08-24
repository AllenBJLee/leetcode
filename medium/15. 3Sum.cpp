class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > vecResult;
        
        if( 3 > nums.size() )
            return vecResult;
        
        sort( nums.begin(), nums.end() );
        
        int nMaxSize = nums.size();
        int nLeft = 0;
        int nRight = 0;
        int nCalc = 0;
        
        for( int nIndex = 0; nIndex < nMaxSize; ++nIndex ) {
            nLeft = nIndex+1;
            nRight = nMaxSize - 1;
            
            if( 0 < nIndex && nums[nIndex-1] == nums[nIndex] )
                continue;
            
            while( nLeft < nRight ) {
                nCalc = nums[nIndex] + nums[nLeft] + nums[nRight];
                if( 0 == nCalc ) {
                    vecResult.push_back( { nums[nIndex], nums[nLeft], nums[nRight] } );
                    
                    int nTemp = nums[nLeft++];
                    
                    while( nTemp == nums[nLeft] && nMaxSize - 1 > nLeft )
                        ++nLeft;
                    
                    nTemp = nums[nRight--];
                    
                    while( nTemp == nums[nRight] && 0 < nRight )
                        --nRight;
                }
                else {
                    ( nCalc < 0 ? ++nLeft : --nRight );
                }
            }
        }
        
        return vecResult;
    }
};