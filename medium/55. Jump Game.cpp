class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        if( 1 == nums.size() ) {
            return true;
        }
        
        int nMax = 0;
        
        for( int i = 0; i < nums.size()-1; ++i ) {
            nMax = nMax > nums[i] + i ? nMax : nums[i] + i;
            
            if( i == nMax )
                break;
        }
        
        bool bReach = false;
        
        if( nMax >= nums.size() - 1 )
            bReach = true;
                
        return bReach;
    }
};