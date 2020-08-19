class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nResult  = nums[0];
        
        int nSum = 0;
        
        for( auto item : nums ) {
            nSum += item;
            
            nResult = max( nSum, nResult );
            
            if( 0 > nSum ) {
                nSum  = 0;
            }
        }
        
        return nResult;
    }
};