class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nCount = nums.size();
        
        // value, idx
        map<int, int> keeped;
        map<int, int>::iterator itFind;
        
        int nCalc = 0;
        
        for( int i = 0; i < nCount; ++i )
        {
            nCalc = target - nums[i];
            
            itFind = keeped.find( nCalc );
            
            if( itFind != keeped.end() ) {
                // find
                return( vector<int>{ itFind->second, i } );
            }
            
            keeped.insert( pair<int, int>( nums[i], i ) );
        }
        
        return( vector<int>() );
    }
};